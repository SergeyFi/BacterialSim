// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "SizeComponent.h"

#include "GameFramework/Actor.h"

#include "BacterialSimulation/Interfaces/HealthComponentInterface.h"

#include "BacterialSimulation/Components/HealthComponent.h"

// Sets default values for this component's properties
USizeComponent::USizeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	InitialSize = 1.0f;

	SetScale(InitialSize);

	if (GetOwner())
	{
		IHealthComponentInterface* HealthComponentIterface = Cast<IHealthComponentInterface>(GetOwner());

		if (HealthComponentIterface)
		{
			HealthComponentIterface->GetHealthComponent()->OnHealthChanged.AddDynamic(this, &USizeComponent::SizeDependOnHealth);
		}
	}
}


// Called when the game starts
void USizeComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USizeComponent::SizeDependOnHealth(float HealthCurrent, float HealthMax) 
{
	float Ratio = HealthCurrent / HealthMax;

	if (Ratio > 0.2f)
	{
		//SetOwnerSize(GetOwnerSize() * Ratio);
	}
}

void USizeComponent::SetScale(float Size) 
{
	if (GetOwner())
	{
		GetOwner()->SetActorScale3D(FVector(Size/10.0f));
	}
}

float USizeComponent::GetScale() 
{
	if (GetOwner())
	{
		return GetOwner()->GetActorScale3D().X*10.0f;
	}

	return 0.0f;
}

float USizeComponent::GetSize() 
{
	if (GetOwner())
	{
		FVector Size = GetOwner()->GetComponentsBoundingBox().GetSize();
		return Size.X*Size.Z*2.0f;
	}

	return 0.0f;
}

void USizeComponent::ShiftOwnerSize(float SizeShift) 
{
	if (GetOwner())
	{
		SetScale(GetScale() - SizeShift);
	}
}

