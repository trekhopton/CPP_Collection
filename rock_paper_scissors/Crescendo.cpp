#include "Crescendo.h"

Crescendo::Crescendo() : Computer(){
    name = "Crescendo";
}
//takes a number and sets move for each
std::string Crescendo::move(int n){
    // a string of correct size (n) to store the moves
    std::string moves(n, ' ');
    // an array of characters (moves) to select from in the right order
    char array[3] = {'P','S','R'};
    // loops through the moves and sets them in the order Paper, Scissors, Rock
    for(int i = 0; i < n; i++){
        moves[i] = array[i%3];
    }
    return moves;
}
