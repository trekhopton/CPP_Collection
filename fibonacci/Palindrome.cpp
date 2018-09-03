#include "Palindrome.h"

Palindrome::Palindrome(){

}

std::string Palindrome::reverseString(std::string str){
    // if the text is only 1 letter then it doesnt need to be reversed
    if(str.length() == 1){
        return str;
    }
    // stores all the letters in the text that come after the first letter
    std::string sub = str.substr(1, std::string::npos);
    // this is a recursive relationship
    // it returns the reversed letters after the first letter and adds the first letter on the end
    // therefore the whole piece of text gets reversed
    return reverseString(sub) + str[0];
}

bool Palindrome::isPalindrome(std::string str){
    // stores the reversed text
    std::string rev = reverseString(str);
    // this iterates over every character in the string and compares it to the 
    // character in the same spot from the reversed text, if the characters are different
    // the text is not a plaindrome so it returns false, if it gets through all the
    // characters then the text is a palindrome and it returns true.
    for(int i = 0; i < str.length(); i++){
        if(str[i] != rev[i]){
            return 0;
        }
    }
    return 1;
}
