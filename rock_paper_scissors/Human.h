#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "Player.h"

class Human : public Player{
public:
    Human();
    std::string move(int n);
    std::string getName();
};

#endif
