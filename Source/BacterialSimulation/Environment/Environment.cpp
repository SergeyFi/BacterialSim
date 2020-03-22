// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Environment.h"
#include "GameFramework/Actor.h"

#include "BacterialSimulation/Environment/Effects/EnvironmentEffect.h"

#include "Engine/World.h"
#include "TimerManager.h"


UEnvironment::UEnvironment() 
{

}

void UEnvironment::UpdateEnvironmentEffects() 
{
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

void UEnvironment::AddEnvironmentEffect(TSubclassOf<class UEnvironmentEffect> NewEffect) 
{
    if (NewEffect)
    {
        EnvironmentEffectClasses.AddUnique(NewEffect);

        UpdateEnvironmentEffects();
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