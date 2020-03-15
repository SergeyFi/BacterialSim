// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GenomeComponent.h"

// Sets default values for this component's properties
UGenomeComponent::UGenomeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGenomeComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UGenomeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

