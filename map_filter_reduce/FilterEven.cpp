#include "FilterEven.h"

FilterEven::FilterEven(){

}

bool FilterEven::f(int x){
    if(x % 2 == 0){
        return 1;
    }
    return 0;
}
