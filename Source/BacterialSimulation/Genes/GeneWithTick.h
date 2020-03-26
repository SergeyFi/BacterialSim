// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"

#include "Tickable.h"

#include "GeneWithTick.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGeneWithTick : public UGene, public FTickableGameObject
{
	GENERATED_BODY()

protected:

public:

	UGeneWithTick();

	virtual void Tick(float DeltaTime) override;

	virtual bool IsTickable() const override;

	virtual bool IsTickableInEditor() const override;

	virtual bool IsTickableWhenPaused() const override;

	virtual TStatId GetStatId() const override;

	virtual UWorld* GetTickableGameObjectWorld() const override;
	
};
