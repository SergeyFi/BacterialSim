// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnvironmentInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnvironmentInterface : public UInterface
{
	GENERATED_BODY()
};


class BACTERIALSIMULATION_API IEnvironmentInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
protected:

	virtual class UEnvironment* GetEnvironment();
};
