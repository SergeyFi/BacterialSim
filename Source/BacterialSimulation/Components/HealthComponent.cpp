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
	HealthRegenStrength = 1.0f;
	HealthRegenEnergyConsume = 1.0f;
	MinimumEnergyToRegen = 20.0f;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (EnergyComponent)
	{
		EnergyComponent->OnEnergyStarvingStart.AddDynamic(this, &UHealthComponent::StartStarving);
		EnergyComponent->OnEnergyStarvingEnd.AddDynamic(this, &UHealthComponent::StopStarving);

		StartHealthRegeneration();
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

	StartHealthRegeneration();
}

void UHealthComponent::Starving() 
{
	RemoveHealth(StarvingDamage);
}

void UHealthComponent::HealthRegeneration() 
{
	if (EnergyComponent->GetEnergyCurrent() >= MinimumEnergyToRegen && !bIsStarving && HealthCurrent < HealthMax)
	{
		AddHealth(HealthRegenStrength);

		EnergyComponent->RemoveEnergy(HealthRegenEnergyConsume);
	}
}

void UHealthComponent::StartHealthRegeneration() 
{
	if (GetWorld() && EnergyComponent)
	{
		GetWorld()->GetTimerManager().SetTimer(HealthRegenerationTimer, this, &UHealthComponent::HealthRegeneration, 1.0f, true);
	}
}

void UHealthComponent::StopHealthRegeneration() 
{
	UWorld* World = GetWorld();
	
	if (World)
	{
		GetWorld()->GetTimerManager().ClearTimer(HealthRegenerationTimer);
	}
}

void UHealthComponent::AddHealth(float Heal) 
{
	HealthCurrent += Heal;

	if (HealthCurrent > HealthMax)
	{
		HealthCurrent = HealthMax;
	}
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