#ifndef REDUCEGENERIC_H
#define REDUCEGENERIC_H
#include <vector>

class ReduceGeneric{
public:
    ReduceGeneric();
    //takes a vector of integers and recursively compares or combines each one using the function binary_operator().
    //The result is only one integer that is the outcome of all the comparisons or the combination.
    int reduce(std::vector<int> v);
private:
    // takes two values and outputs one, is to be implemented by children
    virtual int binary_operator(int x, int y) = 0;
};

#endif
