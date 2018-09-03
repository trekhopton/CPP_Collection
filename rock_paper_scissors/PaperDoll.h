#ifndef PAPERDOLL_H
#define PAPERDOLL_H
#include <iostream>
#include "Computer.h"

class PaperDoll : public Computer {
public:
    PaperDoll();
    std::string move(int n);

};

#endif
