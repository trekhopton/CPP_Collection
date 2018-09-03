#ifndef REDUCEMINIMUM_H
#define REDUCEMINIMUM_H
#include "ReduceGeneric.h"

class ReduceMinimum : public ReduceGeneric {
public:
    ReduceMinimum();
private:
    // returns the minimum of any two given ints
    int binary_operator(int x, int y);
};

#endif
