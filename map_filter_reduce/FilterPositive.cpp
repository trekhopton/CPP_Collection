#include "FilterPositive.h"

FilterPositive::FilterPositive(){

}

bool FilterPositive::f(int x){
    if(x > 0){
        return 1;
    }
    return 0;
}
