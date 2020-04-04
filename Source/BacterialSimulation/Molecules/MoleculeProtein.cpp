// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "MoleculeProtein.h"

#include "BacterialSimulation/Nutrients/AminoAcid.h"


TArray<TSubclassOf<class UNutrient>> AMoleculeProtein::Lisis() 
{
    TArray<TSubclassOf<class UNutrient>> Nutrients;
    Nutrients.Add(UAminoAcid::StaticClass());

    return Nutrients;
}
