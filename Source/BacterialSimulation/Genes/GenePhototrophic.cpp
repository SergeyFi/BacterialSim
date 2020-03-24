// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GenePhototrophic.h"

#include "BacterialSimulation/Components/EnergyComponent.h"

#include "BacterialSimulation/Environment/Environment.h"
#include "BacterialSimulation/Environment/Effects/Light/LightEffect.h"

#include "PaperSpriteComponent.h"


UGenePhototrophic::UGenePhototrophic() 
{
    bNeedGeneCicle = true;

    EnergyGeneration = 0.0f;
    EnergyGenerationMax = 3.0f;
}

void UGenePhototrophic::GeneCicle_Implementation() 
{
    if (OwnerEnergyComponent)
    {
        UEnvironmentEffect* LightEffect = UEnvironment::GetEnvironment()->GetEffectByClass(ULightEffect::StaticClass());
        
        if (LightEffect)
        {
            OwnerEnergyComponent->AddEnergy(EnergyGeneration * LightEffect->GetStrength());
        }
    }
}

void UGenePhototrophic::Mutate_Implementation() 
{
    EnergyGeneration = FMath::RandRange(-0.3f, 0.3f);

    FMath::Clamp(EnergyGeneration, 0.0f, EnergyGenerationMax);
}

void UGenePhototrophic::ActivateGene_Implementation() 
{
    if (OwnerPaperSpriteComponent)
    {
        OwnerPaperSpriteComponent->SetSpriteColor(FLinearColor(0.13f, 0.8f, 0.13f));
    }
}

void UGenePhototrophic::DeactivateGene_Implementation() 
{
    if (OwnerPaperSpriteComponent)
    {
        OwnerPaperSpriteComponent->SetSpriteColor(FLinearColor(1.0f, 1.0f, 1.0f));
    }
}
