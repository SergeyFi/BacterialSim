// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneMovement.h"

#include "GameFramework/Actor.h"

#include "BacterialSimulation/Components/EnergyComponent.h"

#include "Kismet/KismetMathLibrary.h"

UGeneMovement::UGeneMovement() 
{
    bNeedGeneCicle = false;
    MovementSpeed = 80.0f;
    NeedMovement = true;
    EnergyWasteOnMovement = 0.2f;
    MinimumEnergyToWork = 20.0f;
    EnvironmentRatioResistance = 1.0f;
    RotationTimeOut = 1.0f;
}

void UGeneMovement::Tick(float DeltaTime) 
{
    if (bIsActive && NeedMovement && Owner)
    {
        if (OwnerEnergyComponent && OwnerEnergyComponent->GetEnergyCurrent() >= MinimumEnergyToWork)
        {
            MoveForward(DeltaTime);

            ResourcesWasteOnMovement(DeltaTime);
        }
    }
}

void UGeneMovement::MoveForward(float DeltaTime) 
{
    FVector NewLocation = Owner->GetActorLocation() + (Owner->GetActorForwardVector() * MovementSpeed * DeltaTime);

    FHitResult HitResult;
    bool bIsNotHit = Owner->SetActorLocation(NewLocation, true, &HitResult);

    // Rotation timeout
    static bool bNeedRotationTimeOut = false;
    static float RotationTimeOutCurrent = 0.0f;

    if (bNeedRotationTimeOut)
    {
        RotationTimeOutCurrent += 1.0f * DeltaTime;

        if (RotationTimeOutCurrent > RotationTimeOut)
        {
            RotationTimeOutCurrent = 0.0f;
            bNeedRotationTimeOut = false;
        }
    }

    if (!bIsNotHit)
    {
        if (!bNeedRotationTimeOut)
        {
            SetOppositeDirection(HitResult.ImpactPoint);
        }

        bNeedRotationTimeOut = true;
    }
}

void UGeneMovement::ResourcesWasteOnMovement(float DeltaTime) 
{
    if (OwnerEnergyComponent)
    {
        OwnerEnergyComponent->RemoveEnergy((EnergyWasteOnMovement + MovementSpeed/100.0f * EnvironmentRatioResistance) * DeltaTime * 0.5f);
    }
}

void UGeneMovement::SetRandomDirection() 
{
    if (Owner && bIsActive)
    {
        Owner->SetActorRotation(FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 90.0f));
    }
}

void UGeneMovement::SetOppositeDirection(FVector Location) 
{
    FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(Owner->GetActorLocation(), Location);
    Owner->SetActorRotation(FRotator(0.0f, Rotation.Yaw - 180.0f, 90.0f));
}

void UGeneMovement::Mutate_Implementation() 
{
    MovementSpeed += FMath::Clamp(FMath::RandRange(-5.0f, 5.0f), 0.0f, 1000.0f);
    MinimumEnergyToWork += FMath::Clamp(FMath::RandRange(-1.0f, 1.0f),0.0f, 100.0f);
}