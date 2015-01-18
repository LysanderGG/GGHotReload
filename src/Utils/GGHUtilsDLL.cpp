#include "GGHUtilsDLL.h"

#include <windows.h>


/* static */
void*
GGHUtilsDLL::loadLibrary(const std::string& libPath)
{
    // TODO GNU version
    std::string s = libPath + ".dll";
    std::wstring sw(libPath.begin(), libPath.end());
    return (void*)LoadLibraryW(sw.c_str());
}

/* static */
bool
GGHUtilsDLL::unloadLibrary(void* pLib)
{
    return ( FreeLibrary((HMODULE)pLib) ) ? true : false;
}

/* static */
void* 
GGHUtilsDLL::getFunc(const void* pLib, const std::string& sFuncName)
{
    return (void*)GetProcAddress((HINSTANCE)pLib, sFuncName.c_str());
}
