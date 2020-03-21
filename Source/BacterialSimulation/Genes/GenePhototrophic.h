// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"
#include "GenePhototrophic.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGenePhototrophic : public UGene
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene|Phototrophic")
	float EnergyGeneration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene|Phototrophic")
	float EnergyGenerationMax;

public:

	UGenePhototrophic();

	virtual void GeneCicle_Implementation() override;

	virtual void Mutate() override;
};
