// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "Environment.h"

UEnvironment::UEnvironment() 
{
    
}

UEnvironment* UEnvironment::EnvironmentInstance = nullptr;

UEnvironment* UEnvironment::GetEnvironment() 
{
    if (EnvironmentInstance == nullptr)
    {
        EnvironmentInstance = NewObject<UEnvironment>();
    }

    return EnvironmentInstance;
}