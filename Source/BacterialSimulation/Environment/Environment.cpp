// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Environment.h"
#include "GameFramework/Actor.h"

#include "BacterialSimulation/Environment/Effects/EnvironmentEffect.h"

UEnvironment::UEnvironment() 
{
    UpdateEnvironmentEffects();
}

void UEnvironment::UpdateEnvironmentEffects(TSubclassOf<UEnvironmentEffect> Effect) 
{
    if (Effect)
    {
        EnvironmentEffectClasses.Add(Effect);
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



UEnvironment* UEnvironment::EnvironmentInstance = nullptr;

UEnvironment* UEnvironment::GetEnvironment() 
{
    if (EnvironmentInstance == nullptr)
    {
        EnvironmentInstance = NewObject<UEnvironment>();
    }

    return EnvironmentInstance;
}

void UEnvironment::AddActorToEnvironment(AActor* Actor) 
{
    EnvironmentActors.Add(Actor);
}

void UEnvironment::RemoveActorFromEnvironment(class AActor* Actor) 
{
    EnvironmentActors.RemoveSingle(Actor);
}

void UEnvironment::DestroyEnvironment() 
{
    EnvironmentInstance = nullptr;
}

