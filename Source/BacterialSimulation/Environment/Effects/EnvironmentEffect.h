// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnvironmentEffect.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UEnvironmentEffect : public UObject
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
	float EffectStrength;

public:

	UEnvironmentEffect();

	void ApplyEffect(AActor* Target);

	float GetStrength();
};
