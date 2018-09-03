#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"

class QuickSort : Sort {
public:
    QuickSort();
    //sorts given numbers using quicksort in accending order
    void sortNumbers(std::vector<int> & values, int l, int h);

};

#endif
