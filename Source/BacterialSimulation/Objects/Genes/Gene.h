// Copyright 2020 Sergey Firsov. All Rights Reserved.

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

	class IGeneInterface* GeneInterface;

public:

	virtual void Mutate();

	int32 GetGeneLength();

	void SetCellOwner(class AActor* Cell);
	
};
