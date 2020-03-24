// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ComponentInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UComponentInterface : public UInterface
{
	GENERATED_BODY()
};


class BACTERIALSIMULATION_API IComponentInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual class UPaperSpriteComponent* GetPaperSpriteComponent() = 0;

	virtual class UHealthComponent* GetHealthComponent() = 0;

	virtual class UEnergyComponent* GetEnergyComponent() = 0;

	virtual class UGenomeComponent* GetGenomeComponent() = 0;

	virtual class USizeComponent* GetSizeComponent() = 0;
};
