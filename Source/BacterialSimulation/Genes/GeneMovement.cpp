// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneMovement.h"

#include "GameFramework/Actor.h"

#include "BacterialSimulation/Components/EnergyComponent.h"

#include "Kismet/KismetMathLibrary.h"

UGeneMovement::UGeneMovement() 
{
    bNeedGeneCicle = true;
    MovementSpeed = 80.0f;
    NeedMovement = true;
    EnergyWasteOnMovement = 0.2f;
    MinimumEnergyToWork = 20.0f;
    EnvironmentRatioResistance = 1.0f;
    RotationTimeOut = 1.0f;
    GeneCiclePeriod = 15.0f;
}

void UGeneMovement::Tick(float DeltaTime) 
{
    if (bIsActive && NeedMovement && Owner)
    {
        MoveForward(DeltaTime);

        ResourcesWasteOnMovement(DeltaTime);
    }
}

void UGeneMovement::MoveForward(float DeltaTime) 
{
    Owner->SetActorLocation(Owner->GetActorLocation() + (Owner->GetActorForwardVector() * MovementSpeed * DeltaTime));
}

void UGeneMovement::ResourcesWasteOnMovement(float DeltaTime) 
{
    if (OwnerEnergyComponent && OwnerEnergyComponent->GetEnergyCurrent() >= MinimumEnergyToWork)
    {
        OwnerEnergyComponent->RemoveEnergy((EnergyWasteOnMovement + MovementSpeed/100.0f * EnvironmentRatioResistance) * DeltaTime * 0.5f);
    }
}

void UGeneMovement::SetRandomDirection() 
{
    if (Owner && bIsActive)
    {
        Owner->SetActorRotation(FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 0.0f));
    }
}

void UGeneMovement::SetOppositeDirection(FVector Location) 
{
    FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(Owner->GetActorLocation(), Location);
    Owner->SetActorRotation(FRotator(0.0f, Rotation.Yaw - 180.0f, 0.0f));
}

void UGeneMovement::Mutate_Implementation() 
{
    MovementSpeed += FMath::Clamp(FMath::RandRange(-5.0f, 5.0f), 0.0f, 1000.0f);
    MinimumEnergyToWork += FMath::Clamp(FMath::RandRange(-1.0f, 1.0f),0.0f, 100.0f);
    GeneCiclePeriod +=  FMath::Clamp(FMath::RandRange(-1.0f, 1.0f),0.1f, 1000.0f);
}

void UGeneMovement::GeneCicle() 
{
    SetRandomDirection();
}
