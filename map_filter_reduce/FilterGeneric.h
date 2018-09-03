#ifndef FILTERGENERIC_H
#define FILTERGENERIC_H
#include <vector>


class FilterGeneric{
public:
    FilterGeneric();
    // takes a vector of integers and recursively tests each one using the function f().
    // returns a vector containing only the values that are true for the filter.
    std::vector<int> filter(std::vector<int> v);
private:
    // takes a value and returns true or false, is to be implemented by children
    virtual bool f(int x) = 0;
};

#endif
