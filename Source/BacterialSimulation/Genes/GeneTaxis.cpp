// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneTaxis.h"

#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "BacterialSimulation/Interfaces/AttractantInterface.h"
#include "BacterialSimulation/Genes/GeneMovement.h"
#include "BacterialSimulation/Components/GenomeComponent.h"
#include "GameFramework/Actor.h"

UGeneTaxis::UGeneTaxis() 
{
    bNeedGeneCicle = true;
    GeneCiclePeriod = 1.0f;
    SearchPeriodTimeout = 10.0f;
}

void UGeneTaxis::GeneCicle() 
{
    static float LastAttractantSmellStrength = 0.0f;
    float CurrentAttractantSmell = FindSuitableAttractantSmell();

    if (CurrentAttractantSmell < LastAttractantSmellStrength || CurrentAttractantSmell < 0.0f)
    {
        if (GeneMovement)
        {
            GeneMovement->SetRandomDirection();
        }
    }

    // Search period
    static float SearchTime = 0.0f;
    SearchTime += GeneCiclePeriod;

    if (SearchTime >= SearchPeriodTimeout && LastAttractantSmellStrength == 0.0f)
    {
        SearchTime = 0.0f;

        if (GeneMovement)
        {
            GeneMovement->SetRandomDirection();
        }
    }

    LastAttractantSmellStrength = CurrentAttractantSmell;
}

void UGeneTaxis::ActivateGene_Implementation() 
{
    AttachSphereComponentToOwner();

    if (Owner && OwnerGenomeComponent)
    {
        GeneMovement = OwnerGenomeComponent->GetGeneByClass<UGeneMovement>(UGeneMovement::StaticClass());
    }
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

    GeneCiclePeriod += FMath::RandRange(-0.2f, 0.2f);
    GeneCiclePeriod = FMath::Clamp(GeneCiclePeriod, 0.1f, 50.0f);

    SearchPeriodTimeout += FMath::RandRange(-0.5f, 0.5f);
    SearchPeriodTimeout = FMath::Clamp(SearchPeriodTimeout, 0.1f, 50.0f);
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

                    if (FMath::Abs(AttractantScoreCurrent) > FMath::Abs(AttractantScore))
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
    return 0.0f;
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
