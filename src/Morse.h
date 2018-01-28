#pragma once

#include <vector>
#include <string>

namespace Morse {
	const float dot = 0.1f;
	const float dash = 0.3f;
	const float pause = 0.3f;
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

