// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "SizeComponent.h"

#include "GameFramework/Actor.h"

// Sets default values for this component's properties
USizeComponent::USizeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	InitialSize = 1.0f;

	SetOwnerSize(InitialSize);
}


// Called when the game starts
void USizeComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USizeComponent::SetOwnerSize(float Size) 
{
	if (GetOwner())
	{
		GetOwner()->SetActorScale3D(FVector(Size/10.0f));
	}
}

float USizeComponent::GetOwnerSize() 
{
	if (GetOwner())
	{
		return GetOwner()->GetActorScale3D().X*10.0f;
	}

	return 0.0f;
}

void USizeComponent::ShiftOwnerSize(float SizeShift) 
{
	if (GetOwner())
	{
		SetOwnerSize(GetOwnerSize() - SizeShift);
	}
}

