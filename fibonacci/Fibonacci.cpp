#include "Fibonacci.h"

Fibonacci::Fibonacci(){

}

int Fibonacci::fib(int n){
    // the base cases
    if (n < 2) {
        return n;
    }
    // returns the nth fibonacci value, which is given by the sum of the previous two fib values.
    return fib(n-1) + fib(n-2);
}
