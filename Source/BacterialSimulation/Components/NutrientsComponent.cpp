// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "NutrientsComponent.h"

// Sets default values for this component's properties
UNutrientsComponent::UNutrientsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;


}


// Called when the game starts
void UNutrientsComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UNutrientsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

