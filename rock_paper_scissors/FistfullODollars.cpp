#include "FistfullODollars.h"

FistfullODollars::FistfullODollars() : Computer(){
    name = "FistfullODollars";
}
//takes a number and sets move for each
std::string FistfullODollars::move(int n){
    // a string of correct size (n) to store the moves
    std::string moves(n, ' ');
    // an array of characters (moves) to select from in the right order
    char array[3] = {'R','P','P'};
    // loops through the moves and sets them in the order Rock, Paper, Paper
    for(int i = 0; i < n; i++){
        moves[i] = array[i%3];
    }
    return moves;
}
