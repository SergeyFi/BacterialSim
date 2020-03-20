// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GenomeComponent.h"
#include "BacterialSimulation/Genes/Gene.h"

// Sets default values for this component's properties
UGenomeComponent::UGenomeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	MutationPerNLength = 10;
}


// Called when the game starts
void UGenomeComponent::BeginPlay()
{
	Super::BeginPlay();

	AddBaseGenes();

	ActivateGenes();
}

void UGenomeComponent::AddNewRandomGene() 
{
	auto GeneRandomClass = GeneClasses[FMath::RandRange(0, GeneClasses.Max()-1)];

	if (GeneRandomClass)
	{
		Genome.Add(DuplicateObject<UGene>(GeneRandomClass->GetDefaultObject<UGene>(), this));
		Genome.Last()->Init(GetOwner());
		Genome.Last()->ActivateGene();
	}
}

class UGene* UGenomeComponent::FindGeneInGenome(int32 Length) 
{
	int32 CurrentLength = 0;

	for (auto Gene : Genome)
	{
		if (Gene)
		{
			CurrentLength += Gene->GetGeneLength();

			if (CurrentLength >= Length)
			{
				return Gene;
			}
		}
	}

	return nullptr;
}

void UGenomeComponent::AddBaseGenes() 
{
	for (auto GeneClass : BaseGeneClasses)
	{
		if (GeneClass)
		{
			Genome.Add(DuplicateObject<UGene>(GeneClass->GetDefaultObject<UGene>(), this));
			Genome.Last()->Init(GetOwner());
		}
	}
}

void UGenomeComponent::ActivateGenes() 
{
	for (auto Gene : Genome)
	{
		if (Gene)
		{
			Gene->ActivateGene();
		}
	}
}

int32 UGenomeComponent::GetGenomeLength() 
{
	uint32 GenomeLength = 0;

	for (auto Gene : Genome)
	{
		if (Gene)
		{
			GenomeLength += Gene->GetGeneLength();
		}
	}

	return GenomeLength;
}

void UGenomeComponent::Mutate() 
{
	float NewGeneChance = FMath::RandRange(0.0f, 1.0f);

	if (NewGeneChance <= AddNewGeneChance)
	{
		AddNewRandomGene();
	}

	int32 GenomeLength =  GetGenomeLength();

	for (int32 i = 0; i < GenomeLength / MutationPerNLength; i++ )
	{
		int32 RandomLength = FMath::RandRange(0,GenomeLength);
		
		UGene* Gene = FindGeneInGenome(RandomLength);

		if (Gene)
		{
			Gene->Mutate();
		}
	}

}

