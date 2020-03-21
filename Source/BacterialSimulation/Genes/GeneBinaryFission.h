// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"

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

	virtual void GeneCicle_Implementation() override;

	void ConditionCheck();

	void BinaryFission();

	TArray<FVector> FindLocationsToBinaryFission();

	void SpawnOwnerInheritor(FVector SpawnLocation);

	virtual void ResourceWasteOnFission();

public:

	UGeneBinaryFission();
};
