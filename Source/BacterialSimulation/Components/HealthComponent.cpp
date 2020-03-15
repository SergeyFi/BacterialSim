// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "HealthComponent.h"
#include "GameFramework/Actor.h"

#include "BacterialSimulation/Components/EnergyComponent.h"

#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	HealthMax = 100.0f;
	HealthCurrent = HealthMax;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (EnergyComponent)
	{
		EnergyComponent->OnEnergyStarvingStart.AddDynamic(this, &UHealthComponent::StartStarving);
		EnergyComponent->OnEnergyStarvingEnd.AddDynamic(this, &UHealthComponent::StopStarving);
	}
}


void UHealthComponent::RemoveHealth(float Damage) 
{
	HealthCurrent -= Damage;

	if (HealthCurrent <= 0.0f)
	{
		HealthCurrent = 0.0f;
		OnDeath.Broadcast();
	}
}

void UHealthComponent::Starving() 
{
	RemoveHealth(StarvingDamage);
}

void UHealthComponent::StartStarving() 
{
	if (!bIsStarving)
	{
		if (GetWorld())
		{
		GetWorld()->GetTimerManager().SetTimer(TimerStarving, this, &UHealthComponent::Starving, 1.0f, true);

		bIsStarving = true;
		}
	}
}

void UHealthComponent::StopStarving() 
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerStarving);
		
		bIsStarving = false;
	}
}