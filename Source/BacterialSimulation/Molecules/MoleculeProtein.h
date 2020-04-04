// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Molecules/Molecule.h"
#include "MoleculeProtein.generated.h"


UCLASS()
class BACTERIALSIMULATION_API AMoleculeProtein : public AMolecule
{
	GENERATED_BODY()

public:

	virtual TArray<TSubclassOf<class UNutrient>> Lisis() override;
	
};
