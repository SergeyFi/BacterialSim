// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Attractant.h"

// Sets default values
AAttractant::AAttractant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AAttractant::BeginPlay()
{
	Super::BeginPlay();
	
}
