// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneSize.h"

#include "BacterialSimulation/Components/SizeComponent.h"


UGeneSize::UGeneSize() 
{
    bCanBeDeactivated = false;
    SizeRange = 0.1f;
}

void UGeneSize::Mutate_Implementation() 
{
    if (OwnerSizeComponent)
    {
        OwnerSizeComponent->ScaleShift(FMath::RandRange(-SizeRange, SizeRange));
    }
}
