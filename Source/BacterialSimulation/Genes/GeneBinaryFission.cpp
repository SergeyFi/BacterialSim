// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneBinaryFission.h"

#include "Engine/World.h"

#include "BacterialSimulation/Components/EnergyComponent.h"
#include "BacterialSimulation/Components/HealthComponent.h"
#include "BacterialSimulation/Components/GenomeComponent.h"

#include "BacterialSimulation/Interfaces/EnergyComponentInterface.h"
#include "BacterialSimulation/Interfaces/HealthComponentInterface.h"

//#include "DrawDebugHelpers.h"

#include "GameFramework/Actor.h"


UGeneBinaryFission::UGeneBinaryFission() 
{
    MinimumHealthToFission = 90.0f;
    MinimumEnergyToFission = 90.0f;
    EnergyWasteOnFission = 50.0f;
    HealthWasteOnFission = 50.0f;

    bNeedGeneCicle = true;
}

void UGeneBinaryFission::GeneCicle() 
{
    ConditionCheck();
}

void UGeneBinaryFission::ConditionCheck() 
{
    float EnergyCurrent = 0.0f;
    float HealthCurrent = 0.0f;

    if (OwnerEnergyComponent) EnergyCurrent = OwnerEnergyComponent->GetEnergyCurrent();
    
    if (OwnerHealthComponent) HealthCurrent = OwnerHealthComponent->GetHealthCurrent();

    if (EnergyCurrent >= MinimumEnergyToFission && HealthCurrent >= MinimumHealthToFission)
    {
        BinaryFission();
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

        AActor* Inheritor = World->SpawnActor<AActor>(Owner->GetClass(), SpawnTransform, SpawnParams);
    
        TransferResourcesToInheritor(Inheritor);

        TransferGeneToInheritor(Inheritor);
    }
}

void UGeneBinaryFission::TransferGeneToInheritor(AActor* Inheritor) 
{
    if (OwnerGenomeComponent)
    {
        OwnerGenomeComponent->TransferGenesToInheritor(Inheritor);
    }
}

void UGeneBinaryFission::ResourceWasteOnFission() 
{
    if (OwnerEnergyComponent && OwnerHealthComponent)
    {
        OwnerEnergyComponent->RemoveEnergy(EnergyWasteOnFission);
        OwnerHealthComponent->RemoveHealth(HealthWasteOnFission);
    }
}

void UGeneBinaryFission::Mutate_Implementation() 
{
    MutateMinimunEnergyHealth();
}

void UGeneBinaryFission::MutateMinimunEnergyHealth() 
{
    MinimumHealthToFission += FMath::RandRange(-1.0f, 1.0f);
    MinimumEnergyToFission += FMath::RandRange(-1.0f, 1.0f);

    EnergyWasteOnFission += FMath::RandRange(-1.0f, 1.0f);
    HealthWasteOnFission += FMath::RandRange(-1.0f, 1.0f);
}

void UGeneBinaryFission::TransferResourcesToInheritor(AActor* Inheritor) 
{
    if (Inheritor)
    {
        auto EnergyComponentInterface = Cast<IEnergyComponentInterface>(Inheritor);
        UEnergyComponent* InheritorEnergyComponent = nullptr;
        
        if (EnergyComponentInterface) InheritorEnergyComponent = EnergyComponentInterface->GetEnergyComponent();

        if (InheritorEnergyComponent && OwnerEnergyComponent)
        {
            InheritorEnergyComponent->ResetEnergy();
            InheritorEnergyComponent->AddEnergy(EnergyWasteOnFission);
        }

        auto HealthComponentInterface = Cast<IHealthComponentInterface>(Inheritor);
        UHealthComponent* InheritorHealthComponent = nullptr;
        
        if (HealthComponentInterface) InheritorHealthComponent = HealthComponentInterface->GetHealthComponent();

        if (InheritorHealthComponent && OwnerHealthComponent)
        {
            InheritorHealthComponent->ResetHealth();
            InheritorHealthComponent->AddHealth(HealthWasteOnFission);
        }
    }
}
