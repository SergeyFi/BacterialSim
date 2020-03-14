// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeathDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BACTERIALSIMULATION_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health component")
	float HealthCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health component")
	float HealthMax;

public:

	UFUNCTION(BlueprintCallable)
	void RemoveHealth(float Damage);

	UPROPERTY(BlueprintAssignable)
	FDeathDelegate OnDeath;
	
};
