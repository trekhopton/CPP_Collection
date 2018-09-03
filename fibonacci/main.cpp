#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Palindrome.h"
#include "Fibonacci.h"
#include "EfficientFibonacci.h"

int main(){
    //PALINDROME

    //get text from the user
    std::string str;
    std::cin >> str;

    Palindrome p;
    //output the reversed text
    std::cout << p.reverseString(str);

    //check if the text is a palindrome
    if(p.isPalindrome(str)){
        std::cout << " yes ";
    } else {
        std::cout << " no ";
    }
    // FIBONACCI

    EfficientFibonacci fib;
    // get a number from the user
    std::string s;
    std::getline(std::cin, s);
    // output ERROR if the input is empty or a space, if not continue
    if(!s.empty() && s != " "){
        // get rid of the space at the start of the input
        s = s.substr(1, std::string::npos);
        //make sure each character in the input is a number so it can be
        //converted to an int and store the result in a boolean
        bool isNumber = 1;
        for(int i = 0; i < s.length(); i++){
            if(!isdigit(s[i])){
                isNumber = 0;
                break;
            }
        }
        // if the input is a number, continue. if it's not a number output ERROR
        if(isNumber) {
            //convert the input number to an integer called n
            int n = atoi(s.c_str());
            //check if n is a non-negative integer
            //if it is, calculate the nth fibonacci value otherwise output ERROR
            if(n >= 0){
                std::cout << fib.fibDriver(n) << std::endl;
            } else {
                std::cout << "ERROR" << std::endl;
            }
        } else {
            std::cout << "ERROR" << std::endl;
        }
    } else {
        std::cout << "ERROR" << std::endl;
    }

    return 0;
}
