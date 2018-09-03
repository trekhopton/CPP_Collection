#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <iostream>
#include "Computer.h"

class Bureaucrat : public Computer {
public:
    Bureaucrat();
    std::string move(int n);

};

#endif
