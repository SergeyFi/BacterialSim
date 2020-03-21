// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GenePhototrophic.h"

#include "BacterialSimulation/Interfaces/ComponentInterface.h"

#include "BacterialSimulation/Components/EnergyComponent.h"

#include "BacterialSimulation/Environment/Environment.h"
#include "BacterialSimulation/Environment/Effects/Light/LightEffect.h"


UGenePhototrophic::UGenePhototrophic() 
{
    bNeedGeneCicle = true;

    EnergyGeneration = 0.0f;
    EnergyGenerationMax = 3.0f;
}

void UGenePhototrophic::GeneCicle_Implementation() 
{
    if (OwnerComponents)
    {
        if (UEnvironment::GetEnvironment()->EffectIsActive(ULightEffect::StaticClass()))
        {
            OwnerComponents->GetEnergyComponent()->AddEnergy(EnergyGeneration);
        }
    }
}

void UGenePhototrophic::Mutate() 
{
    GeneChangeStateChance();

    EnergyGeneration = FMath::RandRange(-0.3f, 0.3f);

    FMath::Clamp(EnergyGeneration, 0.0f, EnergyGenerationMax);
}
