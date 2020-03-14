// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "HealthComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UHealthComponent::RemoveHealth(float Damage) 
{
	HealthCurrent -= Damage;

	if (HealthCurrent <= 0)
	{
		HealthCurrent = 0.0f;
		OnDeath.Broadcast();
	}
}