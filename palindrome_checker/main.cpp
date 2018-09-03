#include<iostream>
#include "Palindrome.h"

int main(){
    // gets input text & creates a Palindrome object: p
    std::string text;
    std::getline(std::cin,text);
    Palindrome *p = new Palindrome(text);
    // correctly formats p's text
    p->removeNonLetters();
    p->lowerCase();
    // Checks if p is a Palindrome and outputs Yes or No
    if(p->isPalindrome()){
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
