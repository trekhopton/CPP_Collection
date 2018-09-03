#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include "Player.h"

class Computer : public Player {
public:
    Computer();
    virtual std::string move(int n);
    std::string getName();
};

#endif
