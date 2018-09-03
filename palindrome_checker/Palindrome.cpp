#include "Palindrome.h"

// Palindrome constructor that stores a given piece of text
Palindrome::Palindrome(std::string s){
    str = s;
}
// removes non-letters from text
void Palindrome::removeNonLetters(){
    for(unsigned int i = 0; i < str.length(); i++){
        if(isalpha(str[i]) == 0){
            str.erase(i,1);
            i--;
        }
    }
}
// changes all capitals in text to lowercase
void Palindrome::lowerCase(){
    for(unsigned int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
}
// checks if the text is a palindrome
bool Palindrome::isPalindrome(){
    for(unsigned int i = 0; i < str.length(); i++){
        if(str[i] != str[str.length()-1-i]){
            return 0;
        }
    }
    return 1;
}
