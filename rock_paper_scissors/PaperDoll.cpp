#include "PaperDoll.h"

PaperDoll::PaperDoll() : Computer(){
    name = "PaperDoll";
}
//takes a number and sets move for each
std::string PaperDoll::move(int n){
    // a string of correct size (n) to store the moves
    std::string moves(n, ' ');
    // an array of characters (moves) to select from in the right order
    char array[3] = {'P','S','S'};
    // loops through the moves and sets them in the order Paper, Scissors, Scissors
    for(int i = 0; i < n; i++){
        moves[i] = array[i%3];
    }
    return moves;
}
