#include "QuickSort.h"

QuickSort::QuickSort(){

}

void QuickSort::sortNumbers(std::vector<int> & values, int l, int h){
    // if there's only one element then the values are sorted
    if(l == h || l > h){
        return;
    }
    // pick a number from values to split values into two "lower" and "higher" groups
    int pivot;
    if(h - l < 3){
        pivot = values[h];
    } else {
        pivot = values[l+2];
    }
    // make copies of low and high values so we can change them
    int low = l;
    int high = h;
    // divide the values based on the pivot value
    while (low <= high) {
        while (values[low] < pivot)
            low++;
        while (values[high] > pivot)
            high--;
        if (low <= high) {
            int temp = values[low];
            values[low] = values[high];
            values[high] = temp;
            low++;
            high--;
        }
    }
    // sort the two groups using this same method
    sortNumbers(values, l, high);
    sortNumbers(values, low, h);
}
