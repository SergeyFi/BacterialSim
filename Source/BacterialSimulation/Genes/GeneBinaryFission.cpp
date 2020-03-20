// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneBinaryFission.h"

#include "Engine/World.h"

#include "BacterialSimulation/Interfaces/ComponentInterface.h"

#include "BacterialSimulation/Components/EnergyComponent.h"
#include "BacterialSimulation/Components/HealthComponent.h"


UGeneBinaryFission::UGeneBinaryFission() 
{
    MinimumHealthToFission = 90.0f;
    MinimumEnergyToFission = 90.0f;
    EnergyWasteOnFission = 50.0f;
    ConditionsCheckPeriod = 3.0f;
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
    float CheckStep = 10.0f;
    FVector Origin;
    FVector BoxExtent;
    FVector SpawnLocation;

    Owner->GetActorBounds(true, Origin, BoxExtent);

    BoxExtent.X += 10.0f;
    BoxExtent.Y += 10.0f;

    if (BoxExtent.X > BoxExtent.Y) BoxExtent.Y = BoxExtent.X;

    for (float Angle = 0.0f ; Angle < 360.0f; Angle += CheckStep)
    {
        float X = BoxExtent.Y * FMath::Cos(Angle);
        float Y = BoxExtent.Y * FMath::Sin(Angle);

        SpawnLocation.X = X + Origin.X;
        SpawnLocation.Y = Y + Origin.Y;

        UWorld* World = GetWorld();

        if (World)
        {
            FHitResult HitResult;

            FCollisionShape CollisionSphere = FCollisionShape::MakeSphere(BoxExtent.Y*2.0f);

            bool IsHit = World->SweepSingleByChannel(HitResult, SpawnLocation, 
            FVector(X, Y, 1.0f), FQuat::Identity, ECC_WorldStatic, CollisionSphere);

            if (!IsHit)
            {
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
        SpawnParams.Template = Owner;
    
        FTransform SpawnTransform;
        SpawnTransform.SetLocation(SpawnLocation);
    
        World->SpawnActor<AActor>(Owner->GetClass(), SpawnTransform, SpawnParams);
    }
}