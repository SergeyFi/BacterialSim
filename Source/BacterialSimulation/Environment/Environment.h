// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Environment.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, IsBlueprintBase="true"))
class BACTERIALSIMULATION_API UEnvironment : public UObject
{
	GENERATED_BODY()

private:

	UEnvironment();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Environment")
	TArray<class AActor*> EnvironmentActors;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Environment")
	TArray<class UEnvironmentEffect*> EnvironmentEffects;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Environment")
	TArray<TSubclassOf<class UEnvironmentEffect>> EnvironmentEffectClasses;

public:

	static UEnvironment* GetEnvironment();

	void AddActorToEnvironment(class AActor* Actor);

	void RemoveActorFromEnvironment(class AActor* Actor);

	void UpdateEnvironmentEffects();

	void AddEnvironmentEffect(TSubclassOf<class UEnvironmentEffect> NewEffect);

	UEnvironmentEffect* GetEffectByClass(TSubclassOf<class UEnvironmentEffect> Effect);

};
