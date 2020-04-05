// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Observer.h"

// Sets default values
AObserver::AObserver()
{
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AObserver::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void AObserver::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

