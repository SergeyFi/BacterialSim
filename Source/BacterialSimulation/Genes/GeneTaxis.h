// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"
#include "Engine/EngineBaseTypes.h"
#include "GeneTaxis.generated.h"

USTRUCT(BlueprintType)
struct FAttractantStruct
{
    GENERATED_USTRUCT_BODY()

public:

	FAttractantStruct()
	{
		AttractantClass = nullptr;
	}

	FAttractantStruct(UClass*  NewAttractant)
	{
		AttractantClass = NewAttractant;
	}

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=" Attractant")
    TSubclassOf<class AActor>  AttractantClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=" Attractant")
	float Sensitivity = 1.0f;

	void Mutate()
	{
		Sensitivity += FMath::RandRange(-0.1f,0.1f);
		Sensitivity = FMath::Clamp(Sensitivity, -1.0f,1.0f);
	}
};

UCLASS()
class BACTERIALSIMULATION_API UGeneTaxis : public UGene
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gene|Taxis")
	TArray<FAttractantStruct> Attractants;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gene|Taxis")
	float SearchPeriodTimeout;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gene")
	class UGeneMovement* GeneMovement;

	class USphereComponent* SphereComponent;

	virtual void GeneCicle() override;

	virtual void ActivateGene_Implementation() override;

	void AttachSphereComponentToOwner();

	virtual void Mutate_Implementation();

	void MutateAttractants();

	float FindSuitableAttractantSmell();

	float FindAttractantSensitivity(UClass*  AttractantClass);

	float CalculateAttractantSmellStrength(class AActor* Attractant);

public:

	UGeneTaxis();
	
};
