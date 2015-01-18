#include "GGHRLDummy.h"

#include <iostream>

//---------------------------------------------------------------

GGHRLDummy::GGHRLDummy()
  : GGHObject(std::string("RLDummy"))
{
    std::cout << "Create RLDummy" << std::endl;
}

GGHRLDummy::~GGHRLDummy()
{
    std::cout << "Destroy RLDummy" << std::endl;
}

//---------------------------------------------------------------

static
void
_run()
{
    std::cout << "Hello World!" << std::endl;
}

//---------------------------------------------------------------

extern "C" 
{
    GGHRLDLL GGHRLDummy* GGHRLDummy_create() {
        return new GGHRLDummy();
    }

    GGHRLDLL void GGHRLDummy_destroy(GGHRLDummy* pObj) {
        delete pObj;
    }

    GGHRLDLL void GGHRLDummy_run() {
        _run();
    }
}

//---------------------------------------------------------------
