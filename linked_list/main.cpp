#include "LinkedList.h"
#include "Node.h"

#include <iostream>
#include <sstream>
#include <stdlib.h>  

int main(){

    LinkedList l;

    std::string input;
    std::getline(std::cin,input);
    std::string instruction;
    std::istringstream myStream(input);
    while(myStream >> instruction){
        if(instruction == "R"){
            l.removeHead();
        } else if(instruction[0] == 'A'){
            instruction = instruction.substr(1, instruction.size());
            int intput = atoi(instruction.c_str());
            //see my pun?
            l.addTail(intput);
        }
    }

    l.print();
    std::vector<int> v = l.findMid();
    for(int i = 0; i < v.size(); i++){
        std::cout << " " << v[i];
    }
    std::cout << std::endl;

    return 0;
}
