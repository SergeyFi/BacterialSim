// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NutrientsComponent.generated.h"

USTRUCT(BlueprintType)
struct FNutrientStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Nutrient")
	TSubclassOf<class UNutrient> NutrientClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Nutrient")
	float Quantity = 0.0f;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BACTERIALSIMULATION_API UNutrientsComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NutrientComponent")
	TArray<FNutrientStruct> Nutrients;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NutrientComponent")
	float NutrientQuantityMax;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NutrientComponent")
	float NutrientQuantityCurrent;

public:	
	// Sets default values for this component's properties
	UNutrientsComponent();


	void AddNutrient(TSubclassOf<class UNutrient> NutrientClass, float NutrientCount);

	float GetNutrient(TSubclassOf<class UNutrient> NutrientClass, float NutrientCount);
};
