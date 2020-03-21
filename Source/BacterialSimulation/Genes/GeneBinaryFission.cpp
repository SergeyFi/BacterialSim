// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneBinaryFission.h"

#include "Engine/World.h"

#include "BacterialSimulation/Interfaces/ComponentInterface.h"

#include "BacterialSimulation/Components/EnergyComponent.h"
#include "BacterialSimulation/Components/HealthComponent.h"

//#include "DrawDebugHelpers.h"

#include "GameFramework/Actor.h"


UGeneBinaryFission::UGeneBinaryFission() 
{
    MinimumHealthToFission = 90.0f;
    MinimumEnergyToFission = 90.0f;
    EnergyWasteOnFission = 0.0f;

    bNeedGeneCicle = true;
}

void UGeneBinaryFission::GeneCicle_Implementation() 
{
    ConditionCheck();
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

void UGeneBinaryFission::BinaryFission() 
{
    TArray<FVector> SpawnLocations = FindLocationsToBinaryFission();

    if (SpawnLocations.Num() != 0)
    {
        SpawnOwnerInheritor(SpawnLocations[FMath::RandRange(0, SpawnLocations.Num()-1)]);

        ResourceWasteOnFission();
    }
}

TArray<FVector> UGeneBinaryFission::FindLocationsToBinaryFission() 
{
    UWorld* World = GetWorld();

    TArray<FVector> SpawnLocations;

    float CheckStep = 45.0f;
    float DistanceBetween = 1.0f;

    FVector SpawnLocation;
    SpawnLocation = FVector(0.0f, 0.0f, 0.0f);

    FVector Origin;
    FVector BoxExtent;

    Owner->GetActorBounds(true, Origin, BoxExtent);


    for (float Angle = CheckStep ; Angle < 360.0f - CheckStep; Angle += CheckStep)
    {
        float X = Origin.X + (BoxExtent.Y + DistanceBetween) * 2.0f * FMath::Cos(Angle);
        float Y = Origin.Y + (BoxExtent.Y + DistanceBetween) * 2.0f * FMath::Sin(Angle);

        SpawnLocation.X = X;
        SpawnLocation.Y = Y;

        if (World)
        {
            FHitResult HitResult;

            FCollisionShape CollisionSphere = FCollisionShape::MakeSphere(BoxExtent.Y*0.5f);

            bool IsHit = World->SweepSingleByChannel(HitResult, SpawnLocation, 
            FVector(X, Y, 1.0f), FQuat::Identity, ECC_WorldDynamic, CollisionSphere);

            //DrawDebugSphere(World, SpawnLocation, CollisionSphere.GetSphereRadius(), 20, FColor::Purple, true);

            if (!IsHit)
            {
                //DrawDebugSphere(World, SpawnLocation, CollisionSphere.GetSphereRadius(), 20, FColor::Green, true);
                SpawnLocations.Add(SpawnLocation);
            }
        }
    }

    return SpawnLocations;

}

void UGeneBinaryFission::SpawnOwnerInheritor(FVector SpawnLocation) 
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

void UGeneBinaryFission::ResourceWasteOnFission() 
{
    if (OwnerComponents)
    {
        OwnerComponents->GetEnergyComponent()->RemoveEnergy(EnergyWasteOnFission);
    }
}