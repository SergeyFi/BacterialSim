// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"
#include "GeneSize.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGeneSize : public UGene
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gene|Size")
	float SizeRange;

	virtual void Mutate_Implementation() override;

public:

	UGeneSize();
	
};
