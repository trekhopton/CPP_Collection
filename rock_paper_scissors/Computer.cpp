#include "Computer.h"

Computer::Computer() : Player(){
    name = "Computer";
}
//takes a number and sets a fixed move for each
std::string Computer::move(int n){
    // a string of correct size (n) to store the moves
    std::string moves(n, ' ');
    // loops through the moves and sets them all to 'R' for rock
    for(int i = 0; i < n; i++){
        moves[i] = 'R';
    }
    return moves;
}
std::string Computer::getName(){
    return name;
}
