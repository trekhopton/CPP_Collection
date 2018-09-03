#include "ThreePartSearch.h"

ThreePartSearch::ThreePartSearch(){

}

int ThreePartSearch::search(std::vector<int> values, int target,int low, int high){
    //initially we havent found the target,
    //this will stay the same until we do find the target
    //since -1 can't be an index, we use it to say we havent found anything
    int found = -1;
    //if the element at one third or the element at two thirds is the target, return the index of the element
    if(values[low + (high - low)/3] == target){
        found = low + (high - low)/3;
        return found;
    } else if(values[low + 2*(high - low)/3] == target){
        found = low + 2*(high - low)/3;
        return found;
    } else {
        // if there is only one element in the range then nothing has been found
        if(low == high){
            return found;
        }
        // compare the target to the element at one third and at two thirds and earch the corresponding section
        if(target < values[low + (high - low)/3]){
            found = search(values, target, low, low + (high - low)/3);
        } else if(target < values[low + 2*(high - low)/3]) {
            found = search(values, target, low + (high - low)/3+1, low + 2*(high - low)/3);
        } else {
            found = search(values, target, low + 2*(high - low)/3 + 1, high);
        }
    }
    return found;
}
