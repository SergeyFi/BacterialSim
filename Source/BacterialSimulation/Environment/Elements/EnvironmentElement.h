// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnvironmentElement.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UEnvironmentElement : public UObject
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
	float Amount;

public:

	float GetAmount();
	
	void AddAmount(float Value);

	void RemoveAmount(float Value);
};
