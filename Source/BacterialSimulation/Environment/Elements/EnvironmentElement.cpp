// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "EnvironmentElement.h"


float UEnvironmentElement::GetAmount() 
{
    return Amount;
}

void UEnvironmentElement::AddAmount(float Value) 
{
    Amount += Value;
}

void UEnvironmentElement::RemoveAmount(float Value) 
{
    Amount -= Value;

    if (Amount < 0.0f)
    {
        Amount = 0.0f;
    }
}
