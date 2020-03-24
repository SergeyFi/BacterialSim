// Copyright 2020 Sergey Firsov. All Rights Reserved.

// This class with initializer ,pls call init after creation !!

#include "Gene.h"

#include "BacterialSimulation/Interfaces/ComponentInterface.h"

#include "BacterialSimulation/Components/GenomeComponent.h"

#include "Engine/World.h"
#include "TimerManager.h"

UGene::UGene() 
{
    GeneCiclePeriod = 1.0f;
    GeneShutdownChance = 0.1f;
    bCanBeTurnOff = true;
}

void UGene::Mutate() 
{
    if (bCanBeTurnOff)
    {
        GeneChangeStateChance();
    }

    Mutate_Implementation();
}

void UGene::Mutate_Implementation() 
{
    
}

void UGene::ActivateGene_Implementation() 
{  
}

void UGene::DeactivateGene_Implementation() 
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
    if (bNeedGeneCicle)
    {
        StartGeneCicle();
    }

    ActivateGene_Implementation();

    bIsActive = true;
}

void UGene::DeactivateGene() 
{
    if (bNeedGeneCicle)
    {
        StopGeneCicle();
    }

    DeactivateGene_Implementation();

    bIsActive = false;
}

bool UGene::IsActive() 
{
    return bIsActive;
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

void UGene::StartGeneCicle() 
{
    UWorld* World = GetWorld();
    
    if (World)
    {
        World->GetTimerManager().SetTimer(GeneCicleTimer, this, &UGene::GeneCicle_Implementation, GeneCiclePeriod, true);
    }
}

void UGene::GeneCicle_Implementation() 
{
    
}

void UGene::StopGeneCicle() 
{
    UWorld* World = GetWorld();
    
    if (World)
    {
        World->GetTimerManager().ClearTimer(GeneCicleTimer);
    }
}

void UGene::GeneChangeStateChance() 
{
    if (FMath::RandRange(0.0f, 1.0f) < GeneShutdownChance)
    {
        DeactivateGene();
    }
    else if (!bIsActive)
    {
        ActivateGene();
    }
}