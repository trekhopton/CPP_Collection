#include "Convert.h"

Convert::Convert(){

}

std::string Convert::prefixToInfix(std::string s){
    Tree t;
    for(int i = 0; i < s.length(); i+=2){
        t.insert(s.substr(i, 1));
    }
    s = t.getInfix();
    return s;
}
