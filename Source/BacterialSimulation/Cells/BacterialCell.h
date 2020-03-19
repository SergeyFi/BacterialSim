// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BacterialSimulation/Interfaces/ComponentInterface.h"
#include "BacterialCell.generated.h"

UCLASS()
class BACTERIALSIMULATION_API ABacterialCell : public AActor, public IComponentInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABacterialCell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UPaperSpriteComponent* PaperSprite;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UEnergyComponent* EnergyComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UGenomeComponent* GenomeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class USizeComponent* SizeComponent;

public:
	void SetCellVolume(float Volume);

	float GetCellVolume();

	virtual class UHealthComponent* GetHealthComponent() override;

	virtual class UEnergyComponent* GetEnergyComponent() override;

	virtual class UGenomeComponent* GetGenomeComponent() override;

	virtual void SetVolume(float Volume) override;

	virtual float GetVolume() override;
};
