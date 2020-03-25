// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "ObjectSpawner.h"

#include "Engine/World.h"

#include "BacterialSimulation/Interfaces/GenomeComponentInterface.h"
#include "BacterialSimulation/Components/GenomeComponent.h"

// Sets default values
AObjectSpawner::AObjectSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpawnOnBeginPlay = true;

	if (!SpawnOnBeginPlay)
	{
		SpawnObjects();
	}

}

// Called when the game starts or when spawned
void AObjectSpawner::BeginPlay()
{
	Super::BeginPlay();

	if (SpawnOnBeginPlay)
	{
		SpawnObjects();
	}
	
}

void AObjectSpawner::SpawnObjects() 
{
	UWorld* World = GetWorld();

	if (World)
	{
		for (auto SpawnConfiguration : SpawnConfigurations)
		{
			for (int32 i = 0; i < SpawnConfiguration.ObjectCount; i++)
			{
				if (SpawnConfiguration.ActorClass)
				{
					FActorSpawnParameters SpawnParams;
					SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;

					FTransform SpawnTransform;
					SpawnTransform.SetLocation(GenerateSpawnLocation());
					SpawnTransform.SetScale3D(FVector(1.0f, 1.0f, 1.0f));
					SpawnTransform.SetRotation(FQuat(FRotator(0.0f, FMath::RandRange(0.0, 360.0f), 0.0f)));

					AActor* Actor = World->SpawnActor<AActor>(SpawnConfiguration.ActorClass, SpawnTransform, SpawnParams);

					auto GenomeComponentInterface = Cast<IGenomeComponentInterface>(Actor);

					if (GenomeComponentInterface)
					{
						if (GenomeComponentInterface->GetGenomeComponent())
						{
							GenomeComponentInterface->GetGenomeComponent()->AddBaseGenes();
							GenomeComponentInterface->GetGenomeComponent()->ActivateGenes();

						}
					}


				}
			}
		}
	}
}

FVector AObjectSpawner::GenerateSpawnLocation() 
{
	FVector RandomLocation;
	RandomLocation.Y = FMath::RandRange(SpawnYLocation.Y, SpawnXLocation.Y);
	RandomLocation.X = FMath::RandRange(SpawnYLocation.X, SpawnXLocation.X);
	RandomLocation.Z = 0.0f;

	return RandomLocation;
}