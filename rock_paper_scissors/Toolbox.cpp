#include "Toolbox.h"

Toolbox::Toolbox() : Computer(){
    name = "Toolbox";
}
//takes a number and sets move for each
std::string Toolbox::move(int n){
    // a string of correct size (n) to store the moves
    std::string moves(n, ' ');
    // loops through the moves and sets them all to S for scissors
    for(int i = 0; i < n; i++){
        moves[i] = 'S';
    }
    return moves;
}
