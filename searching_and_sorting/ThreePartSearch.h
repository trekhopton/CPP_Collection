#ifndef THREEPARTSEARCH_H
#define THREEPARTSEARCH_H

#include <iostream>
#include <vector>

class ThreePartSearch {
public:
    ThreePartSearch();
    //searches for the given target in a given list of numbers using a three part search similar to binary search
    //returns the index of the value found
    //if no value is found, returns -1
    int search(std::vector<int> values, int target, int low, int high);
};

#endif
