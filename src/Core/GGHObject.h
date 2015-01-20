#ifndef GGHOBJECT_H
#define GGHOBJECT_H

#ifdef BUILDING_CORE_DLL
#define GGHCoreDLL   __declspec( dllexport )
#else 
#define GGHCoreDLL  __declspec( dllimport )
#endif

#include <string>

class GGHObject;

/* Function pointer types */
typedef GGHObject*  (*GGH_fp_create) ();
typedef void        (*GGH_fp_destroy)(GGHObject*);
typedef void        (*GGH_fp_run)    (const GGHObject*);

/* 
 * The GGH_DEFINE_AS_RL macro used to export the create/destroy/run functions. 
 * A class inheriting GGHObject must use this macro.
 *
 * Implementations must define public constructor, destructor and a runInternal method.
 * This runInternal() method must not be called directly but through GGHObject run() method.
 */
#define GGH_DEFINE_AS_RL(_type) \
    extern "C" \
    { \
        GGHRLDLL _type* _type##_create() { \
            return new _type##(); \
        } \
        GGHRLDLL void _type##_destroy(_type##* pObj) { \
            delete pObj; \
        } \
        GGHRLDLL void _type##_run(_type##* pObj) { \
            pObj->runInternal(); \
        } \
    }


/**
 * Base class managing the reloadability.
 */
class GGHCoreDLL GGHObject
{
public:
    GGHObject(const std::string& sBaseName_);
    virtual ~GGHObject();

    void        run     () const;
    bool        reload  ();

private:
    std::string     m_sBaseName;

    GGH_fp_run      m_funcRun;
};

#endif /* GGHRELOADABLEOBJECT_H */
