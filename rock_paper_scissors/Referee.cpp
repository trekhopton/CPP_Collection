#include "Referee.h"

Referee::Referee(){

}
// given the moves from each player and the number of moves, decides what the results are
std::string Referee::decide(std::string p1m, std::string p2m, int n){
    // creates a string of n length to store the results
    std::string result(n, ' ');
    //loops through each set of moves n times: player 1's move and the matching player 2's move
    for(int i = 0; i < n; i++){
        // decides what to do for each move from the first player
        // and then what the result is(stored as a character in the string), given the second player's move
        //'W' for win, 'L' for lose, 'T' for tie and '0' for an invalid move comparison
        switch(p1m[i]){
            case 'R':
                switch(p2m[i]){
                    case 'R':
                        result[i] = 'T';
                        break;
                    case 'P':
                        result[i] = 'L';
                        break;
                    case 'S':
                        result[i] = 'W';
                        break;
                    default:
                        result[i] = '0';
                }
                break;
            case 'P':
                switch(p2m[i]){
                    case 'R':
                        result[i] = 'W';
                        break;
                    case 'P':
                        result[i] = 'T';
                        break;
                    case 'S':
                        result[i] = 'L';
                        break;
                    default:
                        result[i] = '0';
                }
                break;
            case 'S':
                switch(p2m[i]){
                    case 'R':
                        result[i] = 'L';
                        break;
                    case 'P':
                        result[i] = 'W';
                        break;
                    case 'S':
                        result[i] = 'T';
                        break;
                    default:
                        result[i] = '0';
                }
                break;
            default:
                result[i] = '0';
        }
    }
    return result;
}
