// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GenerationInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGenerationInterface : public UInterface
{
	GENERATED_BODY()
};


class BACTERIALSIMULATION_API IGenerationInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Generation")
	int32 GetGeneration();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Generation")
	void SetGeneration(int32 ParentGeneration);
};
