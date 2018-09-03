#include "EfficientFibonacci.h"

EfficientFibonacci::EfficientFibonacci(){
}

int EfficientFibonacci::fibDriver(int n){
    // initializes the cache to a dynamic array of n length containing -1s
    int *fibCache = new int[n];
    for(int i = 0; i < n; i++){
        fibCache[i] = -1;
    }
    // calls the efficient fibonacci calculating function and stores the reult in
    // a variable so that the cache can be deleted to prevent memory leaks
    int fib = efib(n, fibCache);
    delete fibCache;
    return fib;
}

int EfficientFibonacci::efib(int n, int* fibCache){
    //defines the base cases
    if(n < 2){
        return n;
    }
    // checks if the fib value for n-1 has been cached, if not, calculates and stores it
    if(fibCache[n - 1] == -1){
        fibCache[n - 1] = efib(n - 1, fibCache);
    }
    // checks if the fib value for n-2 has been cached, if not, calculates and stores it
    if(fibCache[n - 2] == -1){
        fibCache[n - 2] = efib(n - 2, fibCache);
    }
    // stores the nth fib value in the cache by adding the previous two values in the cache
    fibCache[n] = fibCache[n - 1] + fibCache[n - 2];

    return fibCache[n];
}
