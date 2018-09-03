#include <iostream>
#include <vector>
#include <sstream>
#include "Sort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "RecursiveBinarySearch.h"
#include "ThreePartSearch.h"

int main(){
    //input values into a vector called values
    std::vector<int> values;
    std::string input;
    std::getline(std::cin, input);
    int value;
    std::istringstream stream(input);
    while (stream >> value){
        values.push_back(value);
    }
    //sort values
    QuickSort q = QuickSort();
    q.sortNumbers(values, 0, values.size()-1);
    //search values for 0
    ThreePartSearch s = ThreePartSearch();
    if(s.search(values, 0, 0, values.size()-1) == -1){
        //if 0 isn't found output false
        std::cout << "false ";
    } else {
        //if 0 is found output true
        std::cout << "true ";
    }
    // output all the values
    for(int i = 0; i < values.size(); i++){
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
