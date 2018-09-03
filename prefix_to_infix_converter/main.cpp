#include <iostream>
#include "Convert.h"

int main(){

    std::string input;
    std::getline(std::cin, input);

    Convert c;
    std::string output = c.prefixToInfix(input);
    std::cout << output << std::endl;

    return 0;
}
