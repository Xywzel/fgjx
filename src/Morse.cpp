#include "Morse.h"
#include <iostream>

std::string Morse::encode(std::string message)
{
    std::string rString;
    for (std::string::iterator it=message.begin(); it!=message.end();++it){
        if(*it == ' ')
            rString.append(" ");
        else if(*it >= 'A' && *it <= 'Z')
            rString.append(alphabet[*it - 'A']);
        else if(*it >= '0' && *it <= '9')
            rString.append(alphabet[*it - '0' + 26]);
        else if(*it == '.')
            rString.append(alphabet[36]);
        else
            return "";
        rString.append(" ");
    }
//    std::cout << "Output: " << rString << std::endl;
    return rString;
}

