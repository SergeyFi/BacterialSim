// Copyright 2020 Sergey Firsov. All Rights Reserved.

// This class with initializer ,pls call init after creation !!

#include "Gene.h"

#include "BacterialSimulation/Interfaces/ComponentInterface.h"

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