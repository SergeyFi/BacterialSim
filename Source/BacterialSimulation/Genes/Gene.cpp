// Copyright 2020 Sergey Firsov. All Rights Reserved.

// This class with initializer ,pls call init after creation !!

#include "Gene.h"

#include "BacterialSimulation/Interfaces/EnergyComponentInterface.h"
#include "BacterialSimulation/Interfaces/GenomeComponentInterface.h"
#include "BacterialSimulation/Interfaces/HealthComponentInterface.h"
#include "BacterialSimulation/Interfaces/PaperSpriteInterface.h"
#include "BacterialSimulation/Interfaces/SizeComponentInterface.h"
#include "BacterialSimulation/Interfaces/NutrientComponentInterface.h"

#include "BacterialSimulation/Components/GenomeComponent.h"

#include "Engine/World.h"
#include "TimerManager.h"

UGene::UGene() 
{
    GeneCiclePeriod = 1.0f;
    GeneDeactivationChance = 0.1f;
    GeneActivationChance = 0.1f;
    bCanBeDeactivated = true;
}

void UGene::Mutate() 
{
    if (bCanBeDeactivated)
    {
        GeneChangeActivityChance();
    }

    MutateActivationDeactivation();

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
        IHealthComponentInterface* HealthComponentInterace = Cast<IHealthComponentInterface>(OwnerRef);
        if (HealthComponentInterace) OwnerHealthComponent = HealthComponentInterace->GetHealthComponent_Implementation();

        IEnergyComponentInterface* EnergyComponentInterace = Cast<IEnergyComponentInterface>(OwnerRef);
        if (EnergyComponentInterace) OwnerEnergyComponent = EnergyComponentInterace->GetEnergyComponent();

        IGenomeComponentInterface* GenomeComponentInterace = Cast<IGenomeComponentInterface>(OwnerRef);
        if (GenomeComponentInterace) OwnerGenomeComponent = GenomeComponentInterace->GetGenomeComponent_Implementation();

        IPaperSpriteInterface* PaperSpriteInterace = Cast<IPaperSpriteInterface>(OwnerRef);
        if (PaperSpriteInterace) OwnerPaperSpriteComponent = PaperSpriteInterace->GetPaperSpriteComponent();

        ISizeComponentInterface* SizeComponentInterace = Cast<ISizeComponentInterface>(OwnerRef);
        if (SizeComponentInterace) OwnerSizeComponent = SizeComponentInterace->GetSizeComponent();

        INutrientComponentInterface* NutrientComponentInterace = Cast<INutrientComponentInterface>(OwnerRef);
        if (NutrientComponentInterace) OwnerNutrientComponent = NutrientComponentInterace->GetNutrientComponent();

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
    if (bCanBeDeactivated)
    {
        if (bNeedGeneCicle)
        {
            StopGeneCicle();
        }

        DeactivateGene_Implementation();
        
        bIsActive = false;
    }
}

bool UGene::IsActive() 
{
    return bIsActive;
}

bool UGene::CheckGenesRequiredToWork() 
{
    int32 RequredGenesCount = 0;

    if (OwnerGenomeComponent)
    {
        for (auto Gene : OwnerGenomeComponent->GetGenome())
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
        World->GetTimerManager().SetTimer(GeneCicleTimer, this, &UGene::GeneCicle, GeneCiclePeriod, true);
    }
}

void UGene::GeneCicle() 
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

void UGene::GeneChangeActivityChance() 
{
    if (bIsActive)
    {
        if (FMath::RandRange(0.0f, 1.0f) < GeneDeactivationChance)
        {
            DeactivateGene();
        }
    }
    else 
    {
        if (FMath::RandRange(0.0f, 1.0f) < GeneActivationChance)
        {
            ActivateGene();
        }
    }
}

void UGene::MutateActivationDeactivation() 
{
    GeneDeactivationChance += FMath::RandRange(-0.02f, 0.02f);

    GeneActivationChance += FMath::RandRange(-0.02f, 0.02f);
}