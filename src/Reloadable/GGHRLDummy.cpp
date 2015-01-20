#include "GGHRLDummy.h"

#include <iostream>

//---------------------------------------------------------------

GGHRLDummy::GGHRLDummy()
  : GGHObject(std::string("GGHRLDummy"))
  , i(0)
{
    std::cout << "Create GGHRLDummy" << std::endl;
}

GGHRLDummy::~GGHRLDummy()
{
    std::cout << "Destroy GGHRLDummy" << std::endl;
}

//---------------------------------------------------------------

void GGHRLDummy::runInternal() 
{
    std::cout << i++ << std::endl;
}

//---------------------------------------------------------------

GGH_DEFINE_AS_RL(GGHRLDummy)

//---------------------------------------------------------------
