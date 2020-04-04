// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Lisis/GeneLisis.h"
#include "GeneProteinLisis.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGeneProteinLisis : public UGeneLisis
{
	GENERATED_BODY()
	
protected:

	virtual void Lisis(class AActor* DetectedActor) override;
};
