// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneLisis.h"

#include "BacterialSimulation/Genes/GeneParticleDetection.h"
#include "BacterialSimulation/Components/GenomeComponent.h"

#include "GameFramework/Actor.h"


void UGeneLisis::ActivateGene_Implementation() 
{
    if (OwnerGenomeComponent)
    {
        auto GeneParitcleDetection = 
        OwnerGenomeComponent->GetGeneByClass<UGeneParticleDetection>(UGeneParticleDetection::StaticClass());

        if (GeneParitcleDetection)
        {
            GeneParitcleDetection->OnParticleDetected.AddDynamic(this, &UGeneLisis::Lisis);
            bIsBindingToParticleDetector = true;
        }
        
    }
}

void UGeneLisis::DeactivateGene_Implementation()
{
    if (OwnerGenomeComponent && bIsBindingToParticleDetector)
    {
        auto GeneParitcleDetection = 
        OwnerGenomeComponent->GetGeneByClass<UGeneParticleDetection>(UGeneParticleDetection::StaticClass());

        if (GeneParitcleDetection)
        {
            GeneParitcleDetection->OnParticleDetected.RemoveDynamic(this, &UGeneLisis::Lisis);
        }
        
    }
}

void UGeneLisis::Lisis(AActor* DetectedActor) 
{
    
}