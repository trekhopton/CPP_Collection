#ifndef MAPABSOLUTEVALUE_H
#define MAPABSOLUTEVALUE_H
#include "MapGeneric.h"

class MapAbsoluteValue : public MapGeneric {
public:
    MapAbsoluteValue();
private:
    //returns the given value's absolute value
    int f(int x);
};

#endif
