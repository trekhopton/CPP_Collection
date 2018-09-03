#include "Game.h"
// game contructor, takes two player objects pointers
Game::Game(Player* p1, Player* p2){
    //stores the player objects into their private variables
    player1 = p1;
    player2 = p2;
    //creates a referee ref
    Referee ref = Referee();
}
//updates game logic
void Game::calculateResult(){
    //gives the referee the moves from the players and the number of moves to decide on results
    result = ref.decide(player1->move(numberOfMoves),player2->move(numberOfMoves),numberOfMoves);
}
//displays/outputs the results in the desired format
void Game::display(){
    //loops through the string of results and outputs each char with a space after it
    for(int i = 0; i < result.length(); i++){
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}
std::string Game::getResult(){
    return result;
}
void Game::inputNumberOfMoves(){
    //gets the number of moves from the user
    std::cin >> numberOfMoves;
}
void Game::setNumberOfMoves(int n){
    numberOfMoves = n;
}
