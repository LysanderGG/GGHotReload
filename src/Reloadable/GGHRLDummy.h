#ifndef GGHDUMMY_H
#define GGHDUMMY_H

#ifdef BUILDING_RL_DLL
#define GGHRLDLL   __declspec( dllexport )
#else 
#define GGHRLDLL  __declspec( dllimport )
#endif

#include <GGHObject.h>

class GGHRLDLL GGHRLDummy : public GGHObject
{
public:
    GGHRLDummy();
    ~GGHRLDummy();
};

#endif /* GGHDUMMY_H */
