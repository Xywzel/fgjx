#include "Morse.h"

std::string Morse::encode(std::string string)
{
    std::string rString;
    for (std::string::iterator it=str.begin(); it!=str.end();++it){
        if(*it == ' ')
            rString.append(' ');
        else if(*it >= 'A' && <= 'Z')
            rString.append(alphabet[*it - 'A']);
    }
    std::cout << rString << std::endl;
    return rString;
}


