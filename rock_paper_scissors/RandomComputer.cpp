#include "RandomComputer.h"

RandomComputer::RandomComputer() : Computer(){
    name = "RandomComputer";
}
//takes a number and sets a random move for each
std::string RandomComputer::move(int n){
    // a string of correct size (n) to store the moves
    std::string moves(n, ' ');
    // an array of characters (moves) to select from in a random order
    char array[3] = {'R','P','S'};
    // loops through the moves and sets each as a random move
    for(int i = 0; i < n; i++){
        moves[i] = array[rand() % 3];
    }
    return moves;
}
