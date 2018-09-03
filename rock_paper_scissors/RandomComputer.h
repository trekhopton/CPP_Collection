#ifndef RANDOMCOMPUTER_H
#define RANDOMCOMPUTER_H
#include <iostream>
#include "Computer.h"
#include <stdlib.h>  

class RandomComputer : public Computer {
public:
    RandomComputer();
    std::string move(int n);

};

#endif
