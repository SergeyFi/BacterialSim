// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BacterialSimulation/Interfaces/AttractantInterface.h"
#include "Molecule.generated.h"

UCLASS()
class BACTERIALSIMULATION_API AMolecule : public AActor, public IAttractantInterface
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UPaperSpriteComponent* PaperSprite;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Molecule")
	float Quantity;
	
public:	
	// Sets default values for this actor's properties
	AMolecule();

	float GetQuantity();

	virtual TArray<TSubclassOf<class UNutrient>> Lisis();
};
