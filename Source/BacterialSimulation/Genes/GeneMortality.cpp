// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneMortality.h"

#include "GameFramework/Actor.h"


UGeneMortality::UGeneMortality() 
{
    CurrentLifeSpan = 60;
}

void UGeneMortality::ActivateGene_Implementation() 
{
    if (Owner)
    {
        Owner->SetLifeSpan(CurrentLifeSpan);
    }
}

void UGeneMortality::DeactivateGene_Implementation() 
{
    if (Owner)
    {
        Owner->SetLifeSpan(0.0f);
    }
}

void UGeneMortality::Mutate_Implementation() 
{
    CurrentLifeSpan += FMath::RandRange(-5.0f, 5.0f);
}
