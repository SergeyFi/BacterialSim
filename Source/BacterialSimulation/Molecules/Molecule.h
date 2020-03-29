// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BacterialSimulation/Interfaces/AttractantInterface.h"
#include "Molecule.generated.h"

UCLASS()
class BACTERIALSIMULATION_API AMolecule : public AActor, public IAttractantInterface
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Sets default values for this actor's properties
	AMolecule();
};
