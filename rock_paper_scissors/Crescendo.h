#ifndef CRESCENDO_H
#define CRESCENDO_H
#include <iostream>
#include "Computer.h"

class Crescendo : public Computer {
public:
    Crescendo();
    std::string move(int n);

};

#endif
