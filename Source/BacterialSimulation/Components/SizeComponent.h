// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SizeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BACTERIALSIMULATION_API USizeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USizeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size component")
	float InitialSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size component")
	float MaxScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size component")
	float MinScale;

	UFUNCTION()
	void SizeDependOnHealth(float HealthCurrent, float HealthMax);

public:

	void SetScale(float Size);

	float GetScale();

	float GetSize();

	void ScaleShift(float SizeShift);
};
