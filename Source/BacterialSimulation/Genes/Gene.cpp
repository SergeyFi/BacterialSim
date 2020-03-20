// Copyright 2020 Sergey Firsov. All Rights Reserved.

// This class with initializer ,pls call init after creation !!

#include "Gene.h"

#include "BacterialSimulation/Interfaces/ComponentInterface.h"

UGene::UGene() 
{
    bIsActive = true;
}

void UGene::Mutate() 
{
}

int32 UGene::GetGeneLength() 
{
    return GeneLength;
}

void UGene::Init(class AActor* Owner) 
{
    if (Owner)
    {
        OwnerComponents = Cast<IComponentInterface>(Owner);
    }
}

void UGene::ActivateGene() 
{
    
}