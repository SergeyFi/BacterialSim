// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/GeneWithTick.h"
#include "GeneMovement.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGeneMovement : public UGeneWithTick
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gene|Movement")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gene|Movement")
	float EnergyWasteOnMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gene|Movement")
	float EnvironmentRatioResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gene|Movement")
	float MinimumEnergyToWork;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gene|Movement")
	float RotationTimeOut;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gene|Movement")
	bool NeedMovement;

	void MoveForward(float DeltaTime);

	void ResourcesWasteOnMovement(float DeltaTime);

	void FindOppositeRotation();

	void Tick(float DeltaTime) override;

	void Mutate_Implementation() override;

public:

	UGeneMovement();

	void SetRandomDirection();

	void SetOppositeDirection(FVector Location);
	
};
