// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Environment.h"

// Sets default values
AEnvironment::AEnvironment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnvironment::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnvironment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

