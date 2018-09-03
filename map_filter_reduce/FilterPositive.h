#ifndef FILTERPOSITIVE_H
#define FILTERPOSITIVE_H
#include "FilterGeneric.h"

class FilterPositive : public FilterGeneric {
public:
    FilterPositive();
private:
    // returns true if the given int is positive
    bool f(int x);
};

#endif
