// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Environment.h"
#include "GameFramework/Actor.h"

UEnvironment::UEnvironment() 
{
    
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

