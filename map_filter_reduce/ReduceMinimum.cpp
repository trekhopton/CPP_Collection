#include "ReduceMinimum.h"

ReduceMinimum::ReduceMinimum(){

}

int ReduceMinimum::binary_operator(int x, int y){
    if(x < y){
        return x;
    }
    return y;
}
