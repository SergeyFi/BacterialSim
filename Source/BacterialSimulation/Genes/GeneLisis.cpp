// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneLisis.h"

#include "Components/SphereComponent.h"
#include "BacterialSimulation/Components/SizeComponent.h"


UGeneLisis::UGeneLisis() 
{
    
}

void UGeneLisis::ActivateGene_Implementation() 
{
    AttachSphereComponentToOwner();
}

void UGeneLisis::AttachSphereComponentToOwner() 
{
    if (Owner && OwnerSizeComponent)
    {
        SphereComponent = NewObject<USphereComponent>(Owner);
        SphereComponent->SetSphereRadius(600.0f);
        SphereComponent->bHiddenInGame = false;
        SphereComponent->ShapeColor = FColor::Purple;

        SphereComponent->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
        SphereComponent->RegisterComponent();
        SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &UGeneLisis::OnSphereOverlapBegin);

    }
}

void UGeneLisis::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{

}