#ifndef PALINDROME_H
#define PALINDROME_H

#include <iostream>
#include <string>

class Palindrome{
public:
    Palindrome(std::string s);
    void removeNonLetters();
    void lowerCase();
    bool isPalindrome();
private:
    std::string str;
};

#endif
