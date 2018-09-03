#ifndef REDUCEGCD_H
#define REDUCEGCD_H
#include "ReduceGeneric.h"

class ReduceGCD : public ReduceGeneric {
public:
    ReduceGCD();
private:
    // returns the greatest common denominator of any two given ints
    int binary_operator(int x, int y);
};

#endif
