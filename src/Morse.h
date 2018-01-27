#pragma once

#include <vector>
#include <string>

namespace Morse {
    static std::vector<std::string> alphabet( {
        //A-Z
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
        "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
        "-.--","--..",
        //0-9
        "-----",".----",
        "..---","...--","....-",".....","-....","--...","---..","----.",
        //Period character
        ".-.-.-"
    });
    std::string encode(std::string message);
};

