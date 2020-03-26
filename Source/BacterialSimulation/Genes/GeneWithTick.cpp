// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "GeneWithTick.h"

#include "Engine/Engine.h"

UGeneWithTick::UGeneWithTick() 
{

}

void UGeneWithTick::Tick(float DeltaTime) 
{
    
}

bool UGeneWithTick::IsTickable() const 
{
    return true;
}

bool UGeneWithTick::IsTickableInEditor() const 
{
    return false;
}

bool UGeneWithTick::IsTickableWhenPaused() const 
{
    return false;
}

TStatId UGeneWithTick::GetStatId() const 
{
    return TStatId();
}

UWorld* UGeneWithTick::GetTickableGameObjectWorld() const 
{
    return GetOuter()->GetWorld();
}
