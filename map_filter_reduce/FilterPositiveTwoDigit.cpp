#include "FilterPositiveTwoDigit.h"

FilterPositiveTwoDigit::FilterPositiveTwoDigit(){

}

bool FilterPositiveTwoDigit::f(int x){
    // anything in this range will be poitive and have two digits
    if(x > 9 && x < 100){
        return 1;
    }
    return 0;
}
