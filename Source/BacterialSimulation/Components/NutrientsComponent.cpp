// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "NutrientsComponent.h"

#include "BacterialSimulation/Nutrients/Nutrient.h"

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

void UNutrientsComponent::AddNutrient(TSubclassOf<UNutrient> NutrientClass, float NutrientCount) 
{
	for (auto Nutrient : Nutrients)
	{
		if (Nutrient.NutrientClass == NutrientClass)
		{
			float NutrientQuantityCheck = NutrientCount + NutrientQuantityCurrent;

			if (NutrientQuantityCheck > NutrientQuantityMax)
			{
				 NutrientCount -= NutrientQuantityCheck - NutrientQuantityMax;
			}
			
			Nutrient.Quantity += NutrientCount;
		}
	}
}

float UNutrientsComponent::GetNutrient(TSubclassOf<class UNutrient> NutrientClass, float NutrientCount) 
{
	for (auto Nutrient : Nutrients)
	{
		if (Nutrient.NutrientClass == NutrientClass)
		{
			if (Nutrient.Quantity - NutrientCount >= 0.0f)
			{
				Nutrient.Quantity -= NutrientCount;
				return NutrientCount;
			}
			else
			{
				return Nutrient.Quantity;
			}
			
		}
	}

	return 0.0f;
}