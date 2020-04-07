// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"

#include "GeneBinaryFission.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGeneBinaryFission : public UGene
{
	GENERATED_BODY()

private:

	void MutateMinimunEnergyHealth();

	void TransferResourcesToInheritor(AActor* Inheritor);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene|BinaryFission")
	float MinimumHealthToFission;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene|BinaryFission")
	float MinimumEnergyToFission;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene|BinaryFission")
	float EnergyWasteOnFission;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene|BinaryFission")
	float HealthWasteOnFission;

	FTimerHandle TimerFission;

	void StartTimerBinaryFission();

	virtual void GeneCicle() override;

	void ConditionCheck();

	void BinaryFission();

	TArray<FVector> FindLocationsToBinaryFission();

	void SpawnOwnerInheritor(FVector SpawnLocation);

	void TransferGeneToInheritor(AActor* Inheritor);

	void AddGenerationToInheritor(AActor* Inheritor);

	virtual void ResourceWasteOnFission();

	virtual void Mutate_Implementation() override;

public:

	UGeneBinaryFission();
};
