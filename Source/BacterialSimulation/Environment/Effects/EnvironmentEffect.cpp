// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "EnvironmentEffect.h"

UEnvironmentEffect::UEnvironmentEffect() 
{
    EffectStrength = 1.0f;
}

void UEnvironmentEffect::ApplyEffect(AActor* Target) 
{
    
}

float UEnvironmentEffect::GetStrength() 
{
    return EffectStrength;
}
