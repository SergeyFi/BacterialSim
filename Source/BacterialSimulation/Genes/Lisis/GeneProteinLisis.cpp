// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneProteinLisis.h"

#include "BacterialSimulation/Components/NutrientsComponent.h"
#include "BacterialSimulation/Molecules/MoleculeProtein.h"
#include "BacterialSimulation/Nutrients/AminoAcid.h"


void UGeneProteinLisis::Lisis(class AActor* Target) 
{
    AMoleculeProtein* Protein = Cast<AMoleculeProtein>(Target);

    if (Protein)
    {
        if (OwnerNutrientComponent)
        {
            OwnerNutrientComponent->AddNutrient(UAminoAcid::StaticClass(), Protein->GetQuantity() * 10.0f);
            Protein->Destroy();
        }
    }
}