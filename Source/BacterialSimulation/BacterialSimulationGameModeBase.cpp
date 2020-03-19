// Fill out your copyright notice in the Description page of Project Settings.


#include "BacterialSimulationGameModeBase.h"

#include "BacterialSimulation/Environment/Environment.h"



void ABacterialSimulationGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason) 
{
    if (EndPlayReason == EEndPlayReason::EndPlayInEditor)
    {
        UEnvironment::DestroyEnvironment();
    }
}
