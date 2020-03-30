// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneTaxis.h"

#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "BacterialSimulation/Interfaces/AttractantInterface.h"
#include "GameFramework/Actor.h"

UGeneTaxis::UGeneTaxis() 
{
    bNeedGeneCicle = true;
    GeneCiclePeriod = 0.5f;
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
    for (auto Attractant : Attractants)
    {
        Attractant.Mutate();
    }
}

float UGeneTaxis::FindSuitableAttractantSmell() 
{
    float SmellStrength = 0.0f;
    float AttractantScore = 0.0f;

    if (SphereComponent)
    {
        TArray<AActor*> OverlappingActors;
        SphereComponent->GetOverlappingActors(OverlappingActors);

        for (AActor* Actor : OverlappingActors)
        {
            if (Actor)
            {
                IAttractantInterface* AttractantInterface = Cast<IAttractantInterface>(Actor);
                if (AttractantInterface)
                {
                    float AttractantScoreCurrent = FindAttractantSensitivity(Actor->GetClass());
                    float SmellStrengthCurrent = CalculateAttractantSmellStrength(Actor);

                    AttractantScoreCurrent *= SmellStrength;

                    if (AttractantScoreCurrent > AttractantScore)
                    {
                        AttractantScore = AttractantScoreCurrent;
                        SmellStrength = SmellStrengthCurrent;
                    }
                }
            }
        }
    }

    return SmellStrength;
}

float UGeneTaxis::FindAttractantSensitivity(UClass*  AttractantClass) 
{
    for (auto Attractant : Attractants)
    {
        if (Attractant.AttractantClass == AttractantClass)
        {
            return Attractant.Sensitivity;
        }
    }

    Attractants.Add(FAttractantStruct(AttractantClass));
    return 1.0f;
}

float UGeneTaxis::CalculateAttractantSmellStrength(AActor* Attractant) 
{   
    float SmellStrength = 0.0f;

    if (Owner)
    {
        float SphereRadius = SphereComponent->GetScaledSphereRadius();
        SmellStrength = FVector::Dist(Owner->GetActorLocation(), Attractant->GetActorLocation()) / SphereRadius;
    }

    return SmellStrength;
}
