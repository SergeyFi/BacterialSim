// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PaperSpriteInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPaperSpriteInterface : public UInterface
{
	GENERATED_BODY()
};

class BACTERIALSIMULATION_API IPaperSpriteInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual class UPaperSpriteComponent* GetPaperSpriteComponent() = 0;
};
