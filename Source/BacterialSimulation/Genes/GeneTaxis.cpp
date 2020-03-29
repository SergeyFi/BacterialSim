// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneTaxis.h"

#include "GameFramework/Actor.h"

#include "Components/SphereComponent.h"


UGeneTaxis::UGeneTaxis() 
{
    bNeedGeneCicle = true;
    GeneCiclePeriod = 1.0f;
}

void UGeneTaxis::GeneCicle() 
{
    
}

void UGeneTaxis::ActivateGene_Implementation() 
{
    AttachSphereComponentToOwner();
}

void UGeneTaxis::AttachSphereComponentToOwner() 
{
    if (Owner)
    {
        SphereComponent = NewObject<USphereComponent>(Owner);
        SphereComponent->SetSphereRadius(3000.0f);
        SphereComponent->bHiddenInGame = false;

        SphereComponent->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
        SphereComponent->RegisterComponent();

    }
}

void UGeneTaxis::Mutate_Implementation() 
{
    MutateAttractants();
}

void UGeneTaxis::MutateAttractants() 
{
    //for (auto Attractant : Attractants)
    //{
    //    Attractant.Mutate();
    //}
}
