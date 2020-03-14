// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnergyComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEnergyDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BACTERIALSIMULATION_API UEnergyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnergyComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Energy component")
	float EnergyCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Energy component")
	float EnergyMax;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void RemoveEnergy(float EnergyDamage);

	void AddEnergy(float Energy);

	FEnergyDelegate OnEnergyStarvingStart;

	FEnergyDelegate OnEnergyStarvingEnd;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Energy component")
	float EnergyWaste;
};
