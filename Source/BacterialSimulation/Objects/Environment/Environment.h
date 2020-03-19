// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Environment.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UEnvironment : public UObject
{
	GENERATED_BODY()

private:

	UEnvironment();
	static UEnvironment* EnvironmentInstance;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Environment")
	TArray<class AActor*> EnvironmentActors;

public:

	static UEnvironment* GetEnvironment();

	void AddActorToEnvironment(class AActor* Actor);

	void RemoveActorFromEnvironment(class AActor* Actor);

	static void DestroyEnvironment();

};
