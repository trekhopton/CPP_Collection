#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : Computer(){
    name = "Bureaucrat";
}
//takes a number and sets move for each
std::string Bureaucrat::move(int n){
    // a string of correct size (n) to store the moves
    std::string moves(n, ' ');
    // loops through the moves and sets them all to 'P' for paper
    for(int i = 0; i < n; i++){
        moves[i] = 'P';
    }
    return moves;
}
