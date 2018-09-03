#ifndef MAPTRIPLE_H
#define MAPTRIPLE_H
#include "MapGeneric.h"

class MapTriple : public MapGeneric {
public:
    MapTriple();
private:
    // returns x multiplied by 3
    int f(int x);
};

#endif
