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

	void Tick(float DeltaTime) override;

public:

	UGeneMovement();
	
};
