// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "EnvironmentEffect.h"

UEnvironmentEffect::UEnvironmentEffect() 
{
    EffectStrength = 1.0f;
}

float UEnvironmentEffect::GetStrength() 
{
    return EffectStrength;
}
