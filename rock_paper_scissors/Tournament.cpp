#include "Tournament.h"

Tournament::Tournament(){

}
void Tournament::driver(Computer** players){
    // there's going to be 4 winners of the first round
    // this array is created to store them.
    Computer* round1Winners[4];

    for(int i = 0; i < 4; i++){
        Game g = Game(players[i*2],players[i*2+1]);
        // setting the moves before calculating and storing the result
        g.setNumberOfMoves(5);
        g.calculateResult();
        std::string result = g.getResult();

        int winCount = 0;
        int loseCount = 0;
        int tieCount = 0;
        // counting each result outcome; win lose or tie
        for(int j = 0; j < 5; j++){
            if(result[j] == 'W'){
                winCount++;
            }
            else if(result[j] == 'L'){
                loseCount++;
            }
            else if(result[j] == 'T'){
                tieCount++;
            }
            else {
                std::cout << "error invalid result" << std::endl;
            }
        }
        // checking who has won the round and storing them accordingly
        if(winCount >= loseCount){
            round1Winners[i] = players[i*2];
        } else if(loseCount > winCount){
            round1Winners[i] = players[i*2+1];
        } else {
            std::cout << "error invalid number of results" << std::endl;
        }
    }
    // array created for winners of round 2
    Computer* round2Winners[2];

    for(int i = 0; i < 2; i++){

        Game g = Game(round1Winners[i*2],round1Winners[i*2+1]);

        // setting the moves before calculating and storing the result
        g.setNumberOfMoves(5);
        g.calculateResult();
        std::string result = g.getResult();

        int winCount = 0;
        int loseCount = 0;
        int tieCount = 0;
        // counting each result outcome; win lose or tie
        for(int j = 0; j < 5; j++){
            if(result[j] == 'W'){
                winCount++;
            }
            else if(result[j] == 'L'){
                loseCount++;
            }
            else if(result[j] == 'T'){
                tieCount++;
            }
            else {
                std::cout << "error invalid result" << std::endl;
            }
        }
        // checking who has won the round and storing them accordingly
        if(winCount >= loseCount){
            round2Winners[i] = round1Winners[i*2];
        } else if(loseCount > winCount){
            round2Winners[i] = round1Winners[i*2+1];
        } else {
            std::cout << "error invalid number of results" << std::endl;
        }
    }
    // winner of the tournament
    Computer* winner = NULL;

    Game g = Game(round2Winners[0],round2Winners[1]);
    // setting the moves before calculating and storing the result
    g.setNumberOfMoves(5);
    g.calculateResult();
    std::string result = g.getResult();

    int winCount = 0;
    int loseCount = 0;
    int tieCount = 0;
    // counting each result outcome; win lose or tie
    for(int j = 0; j < 5; j++){
        if(result[j] == 'W'){
            winCount++;
        }
        else if(result[j] == 'L'){
            loseCount++;
        }
        else if(result[j] == 'T'){
            tieCount++;
        }
        else {
            std::cout << "error invalid result" << std::endl;
        }
    }
     // checking who has won the round and storing them accordingly
    if(winCount >= loseCount){
        winner = round2Winners[0];
    } else if(loseCount > winCount){
        winner = round2Winners[1];
    } else {
        std::cout << "error invalid number of results" << std::endl;
    }
    // outputting the winner to the console
    std::cout << winner->getName() << std::endl;
}
