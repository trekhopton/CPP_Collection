#include "ReduceGeneric.h"

ReduceGeneric::ReduceGeneric(){

}

int ReduceGeneric::reduce(std::vector<int> v){
    // base case: when you only have two values return the final result
    if(v.size() == 2){
        return binary_operator(v.front(), v.back());
    }
    //store the last element in the vector
    int temp = v.back();
    //remove the last element from the vector
    v.pop_back();
    //return the result of the rest of the elements and the last element
    return binary_operator(reduce(v), temp);
}
