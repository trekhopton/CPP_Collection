#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
class Player{
public:
    Player();
    virtual std::string move(int n) = 0;
    virtual std::string getName() = 0;
protected:
    std::string name;
};

#endif
