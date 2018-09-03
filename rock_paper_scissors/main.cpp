#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Game.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "Crescendo.h"
#include "FistfullODollars.h"
#include "PaperDoll.h"
#include "RandomComputer.h"
#include "Tournament.h"

int main(){

    Tournament t = Tournament();

    Computer** players = new Computer*[8];

    for(int i = 0; i < 8; i++){
        std::string type;
        std::cin >> type;
        if(type == "Avalanche"){
            players[i] = new Avalanche();
        }
        else if (type == "Bureaucrat"){
            players[i] = new Bureaucrat();
        }
        else if (type == "Toolbox"){
            players[i] = new Toolbox();
        }
        else if (type == "Crescendo"){
            players[i] = new Crescendo();
        }
        else if (type == "FistfullODollars"){
            players[i] = new FistfullODollars();
        }
        else if (type == "PaperDoll"){
            players[i] = new PaperDoll();
        }
        else if (type == "RandomComputer"){
            players[i] = new RandomComputer();
        } else {
            std::cout << "error wrong number of Players" << std::endl;
        }
    }

    t.driver(players);

    delete players;

    return 0;
}
