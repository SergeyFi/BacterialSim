// Copyright 2020 Sergey Firsov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacterialSimulation/Genes/Gene.h"
#include "GeneLisis.generated.h"


UCLASS()
class BACTERIALSIMULATION_API UGeneLisis : public UGene
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gene|Lisis")
	class USphereComponent* SphereComponent;

	virtual void ActivateGene_Implementation() override;

	void AttachSphereComponentToOwner();

public:

	UGeneLisis();

	UFUNCTION()
	void OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
