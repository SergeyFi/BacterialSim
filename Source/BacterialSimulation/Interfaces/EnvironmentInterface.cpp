// Copyright 2020 Sergey Firsov. All Rights Reserved.


#include "EnvironmentInterface.h"

#include "BacterialSimulation/Objects/Environment/Environment.h"

// Add default functionality here for any IEnvironmentInterface functions that are not pure virtual.


class UEnvironment* IEnvironmentInterface::GetEnvironment() 
{
   return UEnvironment::GetEnvironment();
}
