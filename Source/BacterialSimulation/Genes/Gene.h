// Copyright 2020 Sergey Firsov. All Rights Reserved.

// This class with initializer ,pls call init after creation !!

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Gene.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, IsBlueprintBase="true"))
class BACTERIALSIMULATION_API UGene : public UObject
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	int32 GeneLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gene")
	bool bIsActive;

	class IComponentInterface* OwnerComponents;

public:

	UGene();

	virtual void Mutate();

	int32 GetGeneLength();

	void Init(class AActor* Owner);

	virtual void ActivateGene();
};
