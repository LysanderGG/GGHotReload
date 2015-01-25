#include "GGHUtilsDLL.h"

#include <windows.h>


/* static */
void*
GGHUtilsDLL::loadLibrary(const std::string& libPath)
{
    // TODO GNU version
    std::string s = libPath;
    s = s.append(".dll");
    return (void*)LoadLibraryA(s.c_str());
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

static
bool _fileExists(LPCSTR sPath)
{
  DWORD dwAttrib = GetFileAttributesA(sPath);

  return (dwAttrib != INVALID_FILE_ATTRIBUTES && 
         !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

/*static*/ 
bool 
GGHUtilsDLL::moveLibraryToOld(const std::string& libPath)
{
    std::string s = libPath + ".dll";
    std::string o = libPath + "_old.dll";
    if( _fileExists(o.c_str()) ) {
        DeleteFileA(o.c_str());
    }
    return MoveFileA(s.c_str(), o.c_str()) ? true : false;
}
