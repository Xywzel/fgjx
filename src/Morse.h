#pragma once

#include <vector>
#include <string>

namespace Morse {
	const float dot = 0.2f;
	const float dash = 0.6f;
	const float pause = 0.6f;
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
}

