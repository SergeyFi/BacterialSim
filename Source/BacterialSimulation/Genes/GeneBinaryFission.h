// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"

#include "Engine/EngineTypes.h"

#include "GeneBinaryFission.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGeneBinaryFission : public UGene
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	float MinimumHealthToFission;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	float MinimumEnergyToFission;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	float EnergyWasteOnFission;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	float ConditionsCheckPeriod;

	FTimerHandle TimerConditionChecker;

	void StartConditionCheck();

	void ConditionCheck();

	void StopConditionCheck();

	virtual void ActivateGene() override;

	virtual void DeactivateGene() override;

	void BinaryFission();

	void SpawnOwnerCopy(FVector SpawnLocation);

public:

	UGeneBinaryFission();
};
