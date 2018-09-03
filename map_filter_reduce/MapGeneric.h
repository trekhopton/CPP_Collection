#ifndef MAPGENERIC_H
#define MAPGENERIC_H
#include <vector>


class MapGeneric{
public:
    MapGeneric();
    // takes a vector of integers and recursively applies a function
    //to each value in the vector and returns the resulting vector.
    std::vector<int> map(std::vector<int> v);
private:
    //this is the function that is applied in map(), it is to be implemented by children
    virtual int f(int x) = 0;
};

#endif
