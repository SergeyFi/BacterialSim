// Copyright 2020 Sergey Firsov. All Rights Reserved.

// This class with initializer ,pls call init after creation !!

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Templates/SubclassOf.h"

#include "Engine/EngineTypes.h"

#include "Gene.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, IsBlueprintBase="true"))
class BACTERIALSIMULATION_API UGene : public UObject
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	int32 GeneLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	TArray<TSubclassOf<UGene>> GenesRequiredToWork;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	bool bNeedGeneCicle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	float GeneCiclePeriod;

	class IComponentInterface* OwnerComponents;
	class AActor* Owner;

	bool CheckGenesRequiredToWork();

	void StartGeneCicle();

	virtual void GeneCicle_Implementation();

	void StopGeneCicle();

	FTimerHandle GeneCicleTimer;

public:

	UGene();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	bool bIsActive;

	virtual void Mutate();

	int32 GetGeneLength();

	void Init(class AActor* OwnerRef);

	virtual void ActivateGene();

	virtual void DeactivateGene();
};
