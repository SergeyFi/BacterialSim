// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BacterialSimulation/Interfaces/GeneInterface.h"
#include "BacterialCell.generated.h"

UCLASS()
class BACTERIALSIMULATION_API ABacterialCell : public AActor, public IGeneInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABacterialCell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UPaperSpriteComponent* PaperSprite;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UEnergyComponent* EnergyComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UGenomeComponent* GenomeComponent;

public:
	void SetCellVolume(float Volume);

	float GetCellVolume();

	UFUNCTION(BlueprintNativeEvent)
	class UHealthComponent* GetHealthComponent();
	virtual class UHealthComponent* GetHealthComponent_Implementation() override;

	UFUNCTION(BlueprintNativeEvent)
	class UEnergyComponent* GetEnergyComponent();
	virtual class UEnergyComponent* GetEnergyComponent_Implementation() override;

	UFUNCTION(BlueprintNativeEvent)
	void SetVolume(float Volume);
	virtual void SetVolume_Implementation(float Volume) override;

	UFUNCTION(BlueprintNativeEvent)
	float GetVolume();
	virtual float GetVolume_Implementation() override;
};
