// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "BacterialCell.h"

#include "PaperSpriteComponent.h"
#include "Components/StaticMeshComponent.h"

#include "BacterialSimulation/Components/EnergyComponent.h"
#include "BacterialSimulation/Components/HealthComponent.h"
#include "BacterialSimulation/Components/GenomeComponent.h"
#include "BacterialSimulation/Components/SizeComponent.h"
#include "BacterialSimulation/Components/NutrientsComponent.h"

#include "BacterialSimulation/Environment/Environment.h"


#include "Engine/World.h"

// Sets default values
ABacterialCell::ABacterialCell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	//PaperSprite->SetWorldScale3D(FVector(0.1f));
	//RootComponent = PaperSprite;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	EnergyComponent = CreateDefaultSubobject<UEnergyComponent>(TEXT("EnergyComponent"));

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	HealthComponent->EnergyComponent = EnergyComponent;

	GenomeComponent = CreateDefaultSubobject<UGenomeComponent>(TEXT("Genome"));

	SizeComponent = CreateDefaultSubobject<USizeComponent>(TEXT("SizeComponent"));

	NutrientComponent = CreateDefaultSubobject<UNutrientsComponent>(TEXT("NutrientComponent"));
}

// Called when the game starts or when spawned
void ABacterialCell::BeginPlay()
{
	Super::BeginPlay();

	UEnvironment::GetEnvironment()->AddActorToEnvironment(this);
}

void ABacterialCell::Destroyed() 
{
	UEnvironment::GetEnvironment()->RemoveActorFromEnvironment(this);
}

class UPaperSpriteComponent* ABacterialCell::GetPaperSpriteComponent() 
{
	return PaperSprite;
}

class UHealthComponent* ABacterialCell::GetHealthComponent_Implementation() 
{
	return HealthComponent;
}

class UEnergyComponent* ABacterialCell::GetEnergyComponent() 
{
	return EnergyComponent;
}

class UGenomeComponent* ABacterialCell::GetGenomeComponent_Implementation() 
{
	return GenomeComponent;
}

class USizeComponent* ABacterialCell::GetSizeComponent() 
{
	return SizeComponent;
}

class UNutrientsComponent* ABacterialCell::GetNutrientComponent() 
{
	return NutrientComponent;
}