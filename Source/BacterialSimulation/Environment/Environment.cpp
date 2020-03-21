// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Environment.h"
#include "GameFramework/Actor.h"

#include "BacterialSimulation/Environment/Effects/EnvironmentEffect.h"

#include "Engine/World.h"
#include "TimerManager.h"


UEnvironment::UEnvironment() 
{
    ApplyEffectPeriod = 1.0f;

    UpdateEnvironmentEffects();
}

void UEnvironment::ApplyEffectsToActors()
{
    for (auto Effect : EnvironmentEffects)
    {
        if (Effect)
        {
            for (auto Target : EnvironmentActors)
            {
                Effect->ApplyEffect(Target);
            }
        }
    }
}

void UEnvironment::StartApplyEffects() 
{
    UWorld* World = GetWorld();
    
    if (World)
    {
        World->GetTimerManager().SetTimer(TimerEffect, this, &UEnvironment::ApplyEffectsToActors, ApplyEffectPeriod, true);
    }
}

void UEnvironment::StopApplyEffects() 
{
    UWorld* World = GetWorld();
    
    if (World)
    {
        World->GetTimerManager().ClearTimer(TimerEffect);
    }
}


void UEnvironment::UpdateEnvironmentEffects(TSubclassOf<UEnvironmentEffect> NewEffect) 
{
    if (NewEffect)
    {
        EnvironmentEffectClasses.AddUnique(NewEffect);
    }

    EnvironmentEffects.Empty();

    for (auto EffectClass : EnvironmentEffectClasses)
    {
        if (EffectClass)
        {
            UEnvironmentEffect* Effect = DuplicateObject<UEnvironmentEffect>(EffectClass->GetDefaultObject<UEnvironmentEffect>(), this);

            EnvironmentEffects.Add(Effect);
        }
    }
}


UEnvironment* UEnvironment::GetEnvironment() 
{
    return UEnvironment::StaticClass()->GetDefaultObject<UEnvironment>();
}

void UEnvironment::AddActorToEnvironment(AActor* Actor) 
{
    EnvironmentActors.Add(Actor);
}

void UEnvironment::RemoveActorFromEnvironment(class AActor* Actor) 
{
    EnvironmentActors.RemoveSingle(Actor);
}

UEnvironmentEffect* UEnvironment::GetEffectByClass(TSubclassOf<class UEnvironmentEffect> Effect) 
{
    if (Effect)
    {
        for (auto CurrentEffect : EnvironmentEffects)
        {
            if (CurrentEffect)
            {
                if (CurrentEffect->GetClass() == Effect->GetClass())
                {
                    return CurrentEffect;
                }
            }
        }
    }

    return nullptr;
}