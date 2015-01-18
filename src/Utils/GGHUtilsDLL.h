#ifndef GGHUTILSDLL_H
#define GGHUTILSDLL_H

#include <string>

class GGHUtilsDLL
{
public:
    /**
     * @args libPath    Path to the lib without extension.
     */
    static void*    loadLibrary     (const std::string& libPath);
    static bool     unloadLibrary   (void* pLib);
    static void*    getFunc         (const void* pLib, const std::string& sFuncName);
};

#endif /* GGHUTILSDLL_H */
