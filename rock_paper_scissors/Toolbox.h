#ifndef TOOLBOX_H
#define TOOLBOX_H
#include <iostream>
#include "Computer.h"

class Toolbox : public Computer {
public:
    Toolbox();
    std::string move(int n);

};

#endif
