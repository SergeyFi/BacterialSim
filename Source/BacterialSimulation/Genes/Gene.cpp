// Copyright 2020 Sergey Firsov. All Rights Reserved.

// This class with initializer ,pls call init after creation !!

#include "Gene.h"

#include "BacterialSimulation/Interfaces/ComponentInterface.h"

#include "BacterialSimulation/Components/GenomeComponent.h"

UGene::UGene() 
{
}

void UGene::Mutate() 
{
}

int32 UGene::GetGeneLength() 
{
    return GeneLength;
}

void UGene::Init(class AActor* OwnerRef) 
{
    if (OwnerRef)
    {
        OwnerComponents = Cast<IComponentInterface>(OwnerRef);
        Owner = OwnerRef;
    }
}

void UGene::ActivateGene() 
{
    
}

void UGene::DeactivateGene() 
{
    
}
bool UGene::CheckGenesRequiredToWork() 
{
    int32 RequredGenesCount = 0;

    if (OwnerComponents)
    {
        UGenomeComponent* GenomeComponent = OwnerComponents->GetGenomeComponent();

        if (GenomeComponent)
        {
            for (auto Gene : GenomeComponent->GetGenome())
            {
                if (Gene)
                {
                    for (auto RequiredGen : GenesRequiredToWork)
                    {
                        if (RequiredGen->GetClass() == Gene->GetClass())
                        {
                            RequredGenesCount += 1;
                        }
                    }
                }
            }
        }
    }

    if (RequredGenesCount == GenesRequiredToWork.Num())
    {
        return true;
    }
    else return false;
}
