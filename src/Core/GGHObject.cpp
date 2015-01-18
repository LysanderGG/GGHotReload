#include "GGHObject.h"
#include <GGHUtilsDLL.h>

#include <iostream>

//---------------------------------------------------------------

GGHObject::GGHObject(const std::string& sBaseName_)
  : m_sBaseName(sBaseName_)
  , m_funcRun(nullptr)
{
    reload();
}

GGHObject::~GGHObject()
{
}

void 
GGHObject::run() const
{
    if( m_funcRun ) {
        m_funcRun();
    }
}

bool 
GGHObject::reload()
{
    void* pLib = GGHUtilsDLL::loadLibrary("GGHReloadable");
    if( !pLib ) {
        // TODO error message
        return false;
    }

    GGH_fp_run pNewFunc = (GGH_fp_run)GGHUtilsDLL::getFunc(pLib, m_sBaseName + "_run" );
    m_funcRun = ( pNewFunc ) ? pNewFunc : nullptr;
    GGHUtilsDLL::unloadLibrary(pLib);

    return true;
}

//---------------------------------------------------------------
