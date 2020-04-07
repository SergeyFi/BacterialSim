// Copyright 2020 Sergey Firsov. All Rights Reserved.

// This class with initializer ,pls call init after creation !!

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Templates/SubclassOf.h"

#include "Engine/EngineTypes.h"

#include "Gene.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, IsBlueprintBase="true"))
class BACTERIALSIMULATION_API UGene : public UObject
{
	GENERATED_BODY()

private:

	void StartGeneCicle();

	void StopGeneCicle();

	void GeneChangeActivityChance();

	void MutateActivationDeactivation();


protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	FText GeneName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	int32 GeneLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	float GeneDeactivationChance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	float GeneActivationChance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	TArray<TSubclassOf<UGene>> GenesRequiredToWork;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	bool bNeedGeneCicle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	float GeneCiclePeriod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	bool bCanBeDeactivated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gene")
	bool bIsActive;

	class UHealthComponent* OwnerHealthComponent;
	
	class UEnergyComponent* OwnerEnergyComponent;

	class UPaperSpriteComponent* OwnerPaperSpriteComponent;

	class UGenomeComponent* OwnerGenomeComponent;

	class USizeComponent* OwnerSizeComponent;

	class UNutrientsComponent* OwnerNutrientComponent;

	class AActor* Owner;

	bool CheckGenesRequiredToWork();

	virtual void GeneCicle();

	virtual void Mutate_Implementation();

	virtual void ActivateGene_Implementation();

	virtual void DeactivateGene_Implementation();

	FTimerHandle GeneCicleTimer;

public:

	UGene();

	void Mutate();

	int32 GetGeneLength();

	void Init(class AActor* OwnerRef);

	void ActivateGene();

	void DeactivateGene();

	bool IsActive();
};
