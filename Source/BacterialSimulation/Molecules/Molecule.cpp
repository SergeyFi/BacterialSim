// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Molecule.h"

// Sets default values
AMolecule::AMolecule()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMolecule::BeginPlay()
{
	Super::BeginPlay();
	
}
