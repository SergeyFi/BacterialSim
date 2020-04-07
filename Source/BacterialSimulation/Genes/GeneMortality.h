// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"
#include "GeneMortality.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGeneMortality : public UGene
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gene|Mortality")
	float CurrentLifeSpan;

	virtual void ActivateGene_Implementation() override;

	virtual void DeactivateGene_Implementation() override;

	virtual void Mutate_Implementation() override;
public:

	UGeneMortality();
	
};
