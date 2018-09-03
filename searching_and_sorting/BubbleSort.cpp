#include "BubbleSort.h"

BubbleSort::BubbleSort(){

}

void BubbleSort::sortNumbers(std::vector<int> & values){

    bool swapped = true;
    // until the loop goes through the list without swapping any elements,
    // continue checking for values that need sorting
    while(swapped != false){
        swapped = false;
        for(int i = 1; i < values.size(); i++){
            //if a higher value sits below a lower value, swap values
            if(values[i - 1] > values[i]){
                int temp = values[i - 1];
                values[i - 1] = values[i];
                values[i] = temp;
                // remember that a swap has been performed
                swapped = true;
            }
        }
    }
}
