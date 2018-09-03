#include <iostream>
#include <vector>
#include "MapTriple.h"
#include "MapSquare.h"
#include "MapAbsoluteValue.h"
#include "FilterGeneric.h"
#include "FilterEven.h"
#include "FilterPositiveTwoDigit.h"
#include "ReduceGeneric.h"
#include "ReduceMinimum.h"
#include "ReduceGCD.h"

int main(){
    //create a vector and fill it with 20 integers from input, ignore any commas that seperate values
    std::vector<int> values;
    for(int i = 0; i < 20; i++){
        int value;
        std::cin >> value;
        std::cin.ignore(1, ' ');
        values.push_back(value);
    }
    // triple values in the vector
    MapTriple mt;
    values = mt.map(values);
    // convert values to absolute values
    MapAbsoluteValue ma;
    values = ma.map(values);
    // pick out only the positive integers with two digits
    FilterPositiveTwoDigit fptd;
    values = fptd.filter(values);
    // pick out the even values
    FilterEven fe;
    values = fe.filter(values);
    //find and store the minimum value
    ReduceMinimum rm;
    int min = rm.reduce(values);
    // find and store the gcd for the values
    ReduceGCD rgcd;
    int gcd = rgcd.reduce(values);
    // output the minimum and gcd seperated by a space
    std::cout << min << " " << gcd << std::endl;

    return 0;
}
