// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneBinaryFission.h"

#include "Engine/World.h"

#include "BacterialSimulation/Interfaces/ComponentInterface.h"

#include "BacterialSimulation/Components/EnergyComponent.h"
#include "BacterialSimulation/Components/HealthComponent.h"

#include "DrawDebugHelpers.h"

#include "GameFramework/Actor.h"


UGeneBinaryFission::UGeneBinaryFission() 
{
    MinimumHealthToFission = 90.0f;
    MinimumEnergyToFission = 90.0f;
    EnergyWasteOnFission = 50.0f;
    ConditionsCheckPeriod = 1.0f;
}

void UGeneBinaryFission::StartConditionCheck() 
{
    UWorld* World = GetWorld();
    
    if (World)
    {
        World->GetTimerManager().SetTimer(TimerConditionChecker, this, &UGeneBinaryFission::ConditionCheck, ConditionsCheckPeriod, true);
    }
}

void UGeneBinaryFission::ConditionCheck() 
{
    if (OwnerComponents)
    {
        float EnergyCurrent = OwnerComponents->GetEnergyComponent()->GetEnergyCurrent();
        float HealthCurrent = OwnerComponents->GetHealthComponent()->GetHealthCurrent();

        if (EnergyCurrent >= MinimumEnergyToFission && HealthCurrent >= MinimumHealthToFission)
        {
            BinaryFission();
        }
    }
}

void UGeneBinaryFission::StopConditionCheck() 
{
    UWorld* World = GetWorld();
    
    if (World)
    {
        World->GetTimerManager().ClearTimer(TimerConditionChecker);
    }
}

void UGeneBinaryFission::ActivateGene() 
{
    if (Owner)
    {
        bIsActive = true;

        StartConditionCheck();
    }
}

void UGeneBinaryFission::DeactivateGene() 
{
    bIsActive = false;

    StopConditionCheck();
}

void UGeneBinaryFission::BinaryFission() 
{
    UWorld* World = GetWorld();

    float CheckStep = 45.0f;

    FVector SpawnLocation;
    SpawnLocation = FVector(0.0f, 0.0f, 0.0f);

    FVector Origin;
    FVector BoxExtent;

    Owner->GetActorBounds(true, Origin, BoxExtent);


    for (float Angle = CheckStep ; Angle < 360.0f - CheckStep; Angle += CheckStep)
    {
        float X = Origin.X + (BoxExtent.Y + 2.0f) * 2.0f * FMath::Cos(Angle);
        float Y = Origin.Y + (BoxExtent.Y + 2.0f) * 2.0f * FMath::Sin(Angle);

        SpawnLocation.X = X;
        SpawnLocation.Y = Y;

        if (World)
        {
            FHitResult HitResult;

            FCollisionShape CollisionSphere = FCollisionShape::MakeSphere(BoxExtent.Y/2);

            bool IsHit = World->SweepSingleByChannel(HitResult, SpawnLocation, 
            FVector(X, Y, 1.0f), FQuat::Identity, ECC_WorldDynamic, CollisionSphere);

            //DrawDebugSphere(World, SpawnLocation, CollisionSphere.GetSphereRadius(), 20, FColor::Purple, true);

            if (!IsHit)
            {
                //DrawDebugSphere(World, SpawnLocation, CollisionSphere.GetSphereRadius(), 20, FColor::Green, true);
                SpawnOwnerCopy(SpawnLocation);
                break;
            }
        }
    }

}

void UGeneBinaryFission::SpawnOwnerCopy(FVector SpawnLocation) 
{
    UWorld* World = GetWorld();
    
    if (World)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    
        FTransform SpawnTransform;
        SpawnTransform.SetLocation(SpawnLocation);
    
        World->SpawnActor<AActor>(Owner->GetClass(), SpawnTransform, SpawnParams);
    }
}