// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"
#include "GeneTaxis.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGeneTaxis : public UGene
{
	GENERATED_BODY()

protected:

	virtual void GeneCicle() override;

	class USphereComponent* SphereComponent;

	virtual void ActivateGene_Implementation() override;

	void AttachSphereComponentToOwner();

public:

	UGeneTaxis();
	
};