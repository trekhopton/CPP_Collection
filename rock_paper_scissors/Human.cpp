#include "Human.h"

Human::Human() : Player(){
    name = "Human";
}
//takes a number and gets input for that many moves from the user
std::string Human::move(int n){
    // a string of correct size (n) to store the moves
    std::string moves(n, ' ');
    // loop through n times and store the given moves in the string
    for(int i = 0; i < n; i++){
        std::cin >> moves[i];
    }
    return moves;
}

std::string Human::getName(){
    return name;
}
