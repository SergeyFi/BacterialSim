// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GenomeComponent.h"
#include "BacterialSimulation/Genes/Gene.h"

#include "BacterialSimulation/Interfaces/GenomeComponentInterface.h"
#include "BacterialSimulation/Components/GenomeComponent.h"

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

const TArray<class UGene*>& UGenomeComponent::GetGenome()
{
	return Genome;
}

void UGenomeComponent::TransferGenesToInheritor(AActor* Inheritor) 
{
	if (Inheritor)
	{
		auto InheritorGeneComponentInterface = Cast<IGenomeComponentInterface>(Inheritor);
		if (InheritorGeneComponentInterface)
		{
			UGenomeComponent* InheritorGenomeComponent = InheritorGeneComponentInterface->GetGenomeComponent();
			if (InheritorGenomeComponent)
			{
				InheritorGenomeComponent->ClearGenome();

				for (auto Gene : Genome)
				{
					if (Gene)
					{
						UGene* GeneCopy = DuplicateObject<UGene>(Gene, this);
					
						if (GeneCopy->IsActive())
						{
							GeneCopy->DeactivateGene();
							GeneCopy->Init(Inheritor);
							GeneCopy->ActivateGene();
						}

						InheritorGenomeComponent->AddNewGene(GeneCopy);
					}
				}
			}
		}
	}
}

void UGenomeComponent::AddNewGene(class UGene* NewGene) 
{
	if (NewGene)
	{
		Genome.Add(NewGene);
	}
}

void UGenomeComponent::ClearGenome() 
{
	for (auto Gene : Genome)
	{
		if (Gene)
		{
			Gene->DeactivateGene();
			Gene->ConditionalBeginDestroy();
		}
	}

	Genome.Empty();
}
