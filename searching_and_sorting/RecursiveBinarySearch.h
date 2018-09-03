#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H

#include <iostream>
#include <vector>

class RecursiveBinarySearch {
public:
    RecursiveBinarySearch();
    //searches for the given target in a given list of numbers using binary search
    //returns the index of the value found
    //if no value is found, returns -1
    int search(std::vector<int> values, int target, int low, int high);
};

#endif
