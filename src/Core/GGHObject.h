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
typedef void        (*GGH_fp_run)    ();

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
