// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneParticleDetection.h"

#include "Components/SphereComponent.h"
#include "BacterialSimulation/Components/SizeComponent.h"

UGeneParticleDetection::UGeneParticleDetection() 
{
    
}

void UGeneParticleDetection::ActivateGene_Implementation() 
{
    AttachSphereComponentToOwner();
}

void UGeneParticleDetection::AttachSphereComponentToOwner() 
{
    if (Owner && OwnerSizeComponent)
    {
        SphereComponent = NewObject<USphereComponent>(Owner);
        SphereComponent->SetSphereRadius(600.0f);
        SphereComponent->bHiddenInGame = false;
        SphereComponent->ShapeColor = FColor::Purple;

        SphereComponent->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
        SphereComponent->RegisterComponent();
        SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &UGeneParticleDetection::OnSphereOverlapBegin);

    }
}

void UGeneParticleDetection::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    
}