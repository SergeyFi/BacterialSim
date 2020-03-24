// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HealthComponentInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHealthComponentInterface : public UInterface
{
	GENERATED_BODY()
};


class BACTERIALSIMULATION_API IHealthComponentInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual class UHealthComponent* GetHealthComponent() = 0;
};
