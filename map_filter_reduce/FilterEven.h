#ifndef FILTEREVEN_H
#define FILTEREVEN_H
#include "FilterGeneric.h"

class FilterEven : public FilterGeneric {
public:
    FilterEven();
private:
    // takes a value and returns true if it is even
    bool f(int x);
};

#endif
