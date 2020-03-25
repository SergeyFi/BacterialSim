// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeathDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthDelegate, float, HealthCurrent, float, HealthMax);

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health component")
	float HealthRegenStrength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health component")
	float HealthRegenEnergyConsume;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health component")
	float MinimumEnergyToRegen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health component")
	float StarvingDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health component")
	bool bIsStarving;

	void Starving();

	void HealthRegeneration();

	void StartHealthRegeneration();

	void StopHealthRegeneration();

	FTimerHandle HealthRegenerationTimer;

	FTimerHandle TimerStarving;

public:

	UFUNCTION(BlueprintCallable)
	void RemoveHealth(float Damage);

	void AddHealth(float Heal);

	UPROPERTY(BlueprintAssignable)
	FDeathDelegate OnDeath;

	FHealthDelegate OnHealthChanged;

	UFUNCTION()
	void StartStarving();

	UFUNCTION()
	void StopStarving();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health component")
	class UEnergyComponent* EnergyComponent;

	float GetHealthCurrent();

	void ResetHealth();
	
};
