#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sort.h"

class BubbleSort : Sort {
public:
    BubbleSort();
    //sorts given numbers using bubblesort in accending order
    void sortNumbers(std::vector<int> & values);

};

#endif
