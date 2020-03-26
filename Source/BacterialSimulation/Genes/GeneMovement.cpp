// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneMovement.h"

#include "GameFramework/Actor.h"

#include "BacterialSimulation/Components/EnergyComponent.h"

UGeneMovement::UGeneMovement() 
{
    bNeedGeneCicle = false;
    MovementSpeed = 80.0f;
    NeedMovement = true;
    EnergyWasteOnMovement = 0.2f;
    MinimumEnergyToWork = 50.0f;
    EnvironmentRatioResistance = 1.0f;
}

void UGeneMovement::Tick(float DeltaTime) 
{
    if (bIsActive)
    {
        if (OwnerEnergyComponent)
        {
            if (NeedMovement && Owner)
            {
                MoveForward(DeltaTime);

                ResourcesWasteOnMovement(DeltaTime);
            }
        }
    }
}

void UGeneMovement::MoveForward(float DeltaTime) 
{
    FVector NewLocation = Owner->GetActorLocation() + (Owner->GetActorForwardVector() * MovementSpeed * DeltaTime);

    //FHitResult* HitResult;
    bool bIsHit = Owner->SetActorLocation(NewLocation, true);

    if (!bIsHit)
    {
        RandomDirectionChange();
    }
}

void UGeneMovement::ResourcesWasteOnMovement(float DeltaTime) 
{
    if (OwnerEnergyComponent)
    {
        OwnerEnergyComponent->RemoveEnergy((EnergyWasteOnMovement + MovementSpeed/100.0f * EnvironmentRatioResistance) * DeltaTime * 0.5f);
    }
}

void UGeneMovement::RandomDirectionChange() 
{
    if (Owner && bIsActive)
    {
        Owner->SetActorRotation(FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 90.0f));
    }
}

void UGeneMovement::Mutate_Implementation() 
{
    MovementSpeed += FMath::RandRange(-5.0f, 5.0f);
    MinimumEnergyToWork += FMath::RandRange(-1.0f, 1.0f);
}