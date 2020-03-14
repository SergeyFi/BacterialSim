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

	HealthCurrent = HealthMax;

	if (EnergyComponent)
	{
		EnergyComponent->OnEnergyStarvingStart.AddDynamic(this, &UHealthComponent::StartStarving);
		EnergyComponent->OnEnergyStarvingEnd.AddDynamic(this, &UHealthComponent::StopStarving);
	}
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

void UHealthComponent::Starving() 
{
	RemoveHealth(StarvingDamage);
}

void UHealthComponent::StartStarving() 
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(TimerStarving, this, &UHealthComponent::Starving, 1.0f, true);
	}
}

void UHealthComponent::StopStarving() 
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerStarving);
	}
}