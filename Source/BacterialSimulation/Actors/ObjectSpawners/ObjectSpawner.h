// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectSpawner.generated.h"

USTRUCT(BlueprintType)
struct FSpawnConfiguration
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawn")
	int32 ObjectCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawn")
	TSubclassOf<class AActor> ActorClass;
};

UCLASS()
class BACTERIALSIMULATION_API AObjectSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawn")
	bool SpawnOnBeginPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawn")
	TArray<FSpawnConfiguration> SpawnConfigurations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawn", Meta = (MakeEditWidget = true))
	FVector SpawnYLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawn", Meta = (MakeEditWidget = true))
	FVector SpawnXLocation;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnObjects();

	FVector GenerateSpawnLocation();
};
