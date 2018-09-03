#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Player.h"
#include "Computer.h"
#include "Human.h"
#include "Referee.h"

class Game{
public:
    Game(Player* p1, Player* p2);
    void calculateResult();
    void display();
    std::string getResult();
    void inputNumberOfMoves();
    void setNumberOfMoves(int n);
private:
    Player* player1;
    Player* player2;
    int numberOfMoves;
    Referee ref;
    std::string result;
};

#endif
