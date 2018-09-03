#ifndef EFFICIENTFIBONACCI_H
#define EFFICIENTFIBONACCI_H

#include <iostream>

class EfficientFibonacci{
public:
    EfficientFibonacci();
    // fibDriver gets the nth fibanacci value and uses memorization
    // to store already calculated fibonacci numbers
    int fibDriver(int n);
private:
    // efib stands for efficient fibonacci and calculates the nth fibonacci number
    int efib(int n, int* fibCache);
};

#endif
