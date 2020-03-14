// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "EnergyComponent.h"

// Sets default values for this component's properties
UEnergyComponent::UEnergyComponent()
{

	PrimaryComponentTick.bCanEverTick = true;
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
}

