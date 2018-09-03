#ifndef FILTERPOSITIVETWODIGIT_H
#define FILTERPOSITIVETWODIGIT_H
#include "FilterGeneric.h"

class FilterPositiveTwoDigit : public FilterGeneric {
public:
    FilterPositiveTwoDigit();
private:
    // returns true if the given int is positive and has two digits
    bool f(int x);
};

#endif
