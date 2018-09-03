#include "RecursiveBinarySearch.h"

RecursiveBinarySearch::RecursiveBinarySearch(){

}

int RecursiveBinarySearch::search(std::vector<int> values, int target,int low, int high){
    //initially we havent found the target,
    //this will stay the same until we do find the target
    //since -1 can't be an index, we use it to say we havent found anything
    int found = -1;
    //if the middle element is the target, return the index of the element
    if(values[low + (high - low)/2] == target){
        found = low + (high - low)/2;
        return found;
    } else {
        // if there is only one element in the range then nothing has been found
        if(low == high){
            return found;
        }
        //check if the target is lower or higher than the middle value and search the appropriate half
        if(target < values[low + (high - low)/2]){
            found = search(values, target, low, low + (high - low)/2);
        } else {
            found = search(values, target, low + (high - low)/2+1, high);
        }
    }
    return found;
}
