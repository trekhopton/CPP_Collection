#ifndef REFEREE_H
#define REFEREE_H
#include <iostream>
#include "Player.h"
#include "Computer.h"
#include "Human.h"

class Referee{
public:
    Referee();
    std::string decide(std::string p1m, std::string p2m, int n);
};

#endif
