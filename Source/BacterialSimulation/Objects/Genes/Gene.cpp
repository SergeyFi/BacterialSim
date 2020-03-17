// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Gene.h"

#include "BacterialSimulation/Actors/Cells/BacterialCell.h"

void UGene::Mutate() 
{
}

int32 UGene::GetGeneLength() 
{
    return GeneLength;
}

void UGene::SetCellOwner(class AActor* Cell) 
{
    CellOwner = Cast<ABacterialCell>(Cell);
}