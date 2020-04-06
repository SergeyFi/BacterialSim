// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Observer.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AObserver::AObserver()
{
	PrimaryActorTick.bCanEverTick = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	RootComponent = Camera;
	Camera->SetWorldRotation(FRotator(-90.0f, 0.0f, 0.0f));

	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("PawnMovement"));
	PawnMovement->MaxSpeed = 1900.0f;

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

	PlayerInputComponent->BindAxis("MoveForward", this, &AObserver::MoveForward);
	
	PlayerInputComponent->BindAxis("MoveRight", this, &AObserver::MoveRight);

	PlayerInputComponent->BindAxis("MoveUp", this, &AObserver::MoveUp);

}

void AObserver::MoveForward(float Value) 
{
	AddMovementInput(GetActorUpVector(), Value);
}

void AObserver::MoveRight(float Value) 
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AObserver::MoveUp(float Value) 
{
	AddMovementInput(GetActorForwardVector(), Value);
}
