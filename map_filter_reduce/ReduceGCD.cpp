#include "ReduceGCD.h"

ReduceGCD::ReduceGCD(){

}

int ReduceGCD::binary_operator(int x, int y){
    if(y == 0){
        return x;
    }
    if(x%y == 0){
        return y;
    }
    return binary_operator(y, x%y);
}
