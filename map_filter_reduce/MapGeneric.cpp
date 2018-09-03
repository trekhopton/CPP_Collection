#include "MapGeneric.h"

MapGeneric::MapGeneric(){

}

std::vector<int> MapGeneric::map(std::vector<int> v){
    // base case: when the vector doesnt have any values return the empty vector
    if(v.size() == 0){
        return v;
    }
    // temporarily store the f of the last value in the vector
    int temp = f(v.back());
    // get rid of the last value in the vector
    v.pop_back();
    // create a new vector that is the map of all the rest of the values
    std::vector<int> nv = map(v);
    //add back on the last value
    nv.push_back(temp);

    return nv;
}
