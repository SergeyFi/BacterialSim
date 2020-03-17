// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "BacterialCell.h"

#include "PaperSpriteComponent.h"

#include "BacterialSimulation/Components/EnergyComponent.h"
#include "BacterialSimulation/Components/HealthComponent.h"
#include "BacterialSimulation/Components/GenomeComponent.h"

// Sets default values
ABacterialCell::ABacterialCell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	PaperSprite->SetWorldScale3D(FVector(0.1f));
	RootComponent = PaperSprite;

	EnergyComponent = CreateDefaultSubobject<UEnergyComponent>(TEXT("EnergyComponent"));

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	HealthComponent->EnergyComponent = EnergyComponent;

	GenomeComponent = CreateDefaultSubobject<UGenomeComponent>(TEXT("Genome"));
}

// Called when the game starts or when spawned
void ABacterialCell::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABacterialCell::SetCellVolume(float Volume) 
{
	PaperSprite->SetWorldScale3D(FVector(Volume/10.0f));
}

float ABacterialCell::GetCellVolume() 
{
	return PaperSprite->GetRelativeScale3D().X*10.0f;
}

class UHealthComponent* ABacterialCell::GetHealthComponent_Implementation() 
{
	return HealthComponent;
}

class UEnergyComponent* ABacterialCell::GetEnergyComponent_Implementation() 
{
	return EnergyComponent;
}

void ABacterialCell::SetVolume_Implementation(float Volume) 
{
	SetCellVolume(Volume);
}

float ABacterialCell::GetVolume_Implementation() 
{
	return GetCellVolume();
}