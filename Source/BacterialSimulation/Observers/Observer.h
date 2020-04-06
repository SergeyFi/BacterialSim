// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Observer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClickDelegate, AActor*, Actor);

UCLASS()
class BACTERIALSIMULATION_API AObserver : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AObserver();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Observer")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Observer")
	class UFloatingPawnMovement* PawnMovement;

	void MoveForward(float Value);
	
	void MoveRight(float Value);

	void MoveUp(float Value);

	void ClickLeftMB();

public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintAssignable)
	FClickDelegate OnActorClicked;

};
