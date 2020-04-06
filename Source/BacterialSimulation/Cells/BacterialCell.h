// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BacterialSimulation/Interfaces/EnergyComponentInterface.h"
#include "BacterialSimulation/Interfaces/GenomeComponentInterface.h"
#include "BacterialSimulation/Interfaces/HealthComponentInterface.h"
#include "BacterialSimulation/Interfaces/PaperSpriteInterface.h"
#include "BacterialSimulation/Interfaces/SizeComponentInterface.h"
#include "BacterialSimulation/Interfaces/NutrientComponentInterface.h"

#include "BacterialCell.generated.h"

UCLASS()
class BACTERIALSIMULATION_API ABacterialCell : public AActor, public IEnergyComponentInterface, public IGenomeComponentInterface, 
public IHealthComponentInterface, public IPaperSpriteInterface, public ISizeComponentInterface, public INutrientComponentInterface

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
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UEnergyComponent* EnergyComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UGenomeComponent* GenomeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class USizeComponent* SizeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UNutrientsComponent* NutrientComponent;

public:

	virtual class UPaperSpriteComponent* GetPaperSpriteComponent() override;

	class UHealthComponent* GetHealthComponent_Implementation();

	virtual class UEnergyComponent* GetEnergyComponent() override;

	virtual class UGenomeComponent* GetGenomeComponent() override;

	virtual class USizeComponent* GetSizeComponent() override;

	virtual class UNutrientsComponent* GetNutrientComponent() override;
};
