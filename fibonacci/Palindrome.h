#include <iostream>
#ifndef PALINDROME_H
#define PALINDROME_H

class Palindrome{
public:
    Palindrome();
    // reverseString is given some text and gives back that text reversed
    std::string reverseString(std::string str);
    // isPalindrome is given some text and checks if it is a palindrome, it returns true or false
    bool isPalindrome(std::string str);
};

#endif
