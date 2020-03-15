// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "EnergyComponent.h"

// Sets default values for this component's properties
UEnergyComponent::UEnergyComponent()
{

	PrimaryComponentTick.bCanEverTick = true;
	EnergyMax = 100.0f;
	EnergyCurrent = EnergyMax;

	SetComponentTickInterval(1.0f);
}


// Called when the game starts
void UEnergyComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UEnergyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	RemoveEnergy(EnergyWaste);
}

void UEnergyComponent::AddEnergy(float Energy) 
{
	EnergyCurrent += Energy;

	if (EnergyCurrent > 0.0f)
	{
		OnEnergyStarvingEnd.Broadcast();
	}

	if (EnergyCurrent > EnergyMax) 
	{
		EnergyCurrent = EnergyMax;
	}
}

void UEnergyComponent::AddEnergyWaste(float Energy) 
{
	EnergyWaste += Energy;
}

void UEnergyComponent::RemoveEnergyWaste(float Energy) 
{
	EnergyWaste -= Energy;
}

void UEnergyComponent::RemoveEnergy(float EnergyDamage) 
{
	EnergyCurrent -= EnergyDamage;

	if (EnergyCurrent <= 0.0f)
	{
		EnergyCurrent = 0.0f;
		OnEnergyStarvingStart.Broadcast();
	}
}

