// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "BacterialCell.h"

// Sets default values
ABacterialCell::ABacterialCell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABacterialCell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABacterialCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

