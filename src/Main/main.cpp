#include <GGHUtilsDLL.h>
#include <GGHRLDummy.h>

int main(int argc, char** argv)
{
    bool bPause = true;
    GGHRLDummy* pObj = nullptr;
    char c = 0;
    void* pLib = nullptr;
    GGH_fp_create  pFuncCreate  = nullptr;
    GGH_fp_destroy pFuncDestroy = nullptr;

    do {
        c = getchar();

        if( bPause ) {
            bool bRes = GGHUtilsDLL::moveLibraryToOld("E:\\Dev\\GGHotReload\\projects\\Debug\\GGHReloadable");
            if( !bRes ) {
                return -1;
            }

            pLib = GGHUtilsDLL::loadLibrary("GGHReloadable_old");
            if( !pLib ) {
                return -1;
            }
            pFuncCreate  = (GGH_fp_create)GGHUtilsDLL::getFunc(pLib, "GGHRLDummy_create");
            pFuncDestroy = (GGH_fp_destroy)GGHUtilsDLL::getFunc(pLib, "GGHRLDummy_destroy");
            if( !pFuncCreate || !pFuncDestroy ) {
                return -1;
            }

            pObj = (GGHRLDummy*)pFuncCreate();
            bPause = false;
        }

        if( 'r' == c ) {
            pObj->reload();
        }

        if( 'p' == c ) {
            pFuncDestroy(pObj);
            pObj = nullptr;
            GGHUtilsDLL::unloadLibrary(pLib);
            pLib = nullptr;
            pFuncCreate = nullptr;
            pFuncDestroy = nullptr;
            bPause = true;

            getchar();
        }

        if( pObj ) {
            pObj->run();
        }

    } while('q' != c);

    return 0;
}
