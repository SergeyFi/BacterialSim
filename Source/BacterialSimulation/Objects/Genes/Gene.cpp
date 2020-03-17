// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Gene.h"

#include "BacterialSimulation/Interfaces/GeneInterface.h"

void UGene::Mutate() 
{
}

int32 UGene::GetGeneLength() 
{
    return GeneLength;
}

void UGene::SetCellOwner(class AActor* Cell) 
{
    GeneInterface = Cast<IGeneInterface>(Cell);
}