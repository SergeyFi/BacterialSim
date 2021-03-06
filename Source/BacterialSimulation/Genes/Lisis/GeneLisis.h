// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"
#include "GeneLisis.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGeneLisis : public UGene
{
	GENERATED_BODY()

protected:

	bool bIsBindingToParticleDetector;

	UFUNCTION()
	virtual void Lisis(class AActor* DetectedActor);

	virtual void ActivateGene_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gene|Lisis")
	TSubclassOf<class AActor> LisisTarget;

	virtual void DeactivateGene_Implementation();
};
