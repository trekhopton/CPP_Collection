#ifndef AVALANCHE_H
#define AVALANCHE_H
#include <iostream>
#include "Computer.h"

class Avalanche : public Computer {
public:
    Avalanche();
    std::string move(int n);

};

#endif
