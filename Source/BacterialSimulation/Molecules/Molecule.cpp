// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Molecule.h"

#include "PaperSpriteComponent.h"

#include "BacterialSimulation/Nutrients/Nutrient.h"

// Sets default values
AMolecule::AMolecule()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	RootComponent = PaperSprite;

	Quantity = 5.0f;
}

// Called when the game starts or when spawned
void AMolecule::BeginPlay()
{
	Super::BeginPlay();

}

float AMolecule::GetQuantity() 
{
	return Quantity;
}

TArray<TSubclassOf<class UNutrient>> AMolecule::Lisis() 
{
	TArray<TSubclassOf<class UNutrient>> Nutrients;

	return Nutrients;
}