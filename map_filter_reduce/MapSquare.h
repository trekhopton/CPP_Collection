#ifndef MAPSQUARE_H
#define MAPSQUARE_H
#include "MapGeneric.h"

class MapSquare : public MapGeneric {
public:
    MapSquare();
private:
    // returns x squared
    int f(int x);
};

#endif
