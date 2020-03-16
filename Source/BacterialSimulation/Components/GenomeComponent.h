// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GenomeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BACTERIALSIMULATION_API UGenomeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGenomeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genome component")
	int32 MutationPer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genome component")
	float AddNewGeneChance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genome component")
	TArray<class UGene*> Genome;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genome component")
	TArray<TSubclassOf<class UGene>> GeneClasses;

	void AddNewRandomGene();

	class UGene* FindGeneInGenome(int32 Length);

public:

	int32 GetGenomeLength();

	void Mutate();
		
};
