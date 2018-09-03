#include "FilterGeneric.h"

FilterGeneric::FilterGeneric(){

}

std::vector<int> FilterGeneric::filter(std::vector<int> v){
    // base case: when the vector is empty return it
    if(v.size() == 0){
        return v;
    }
    // store the last element and the f of it
    bool b = f(v.back());
    int temp = v.back();
    //remove the last element from the vector
    v.pop_back();
    //filter the rest and store them in a new vector
    std::vector<int> nv = filter(v);
    // if the value filtered out then put it back on the vector
    if(b){
        nv.push_back(temp);
    }

    return nv;
}
