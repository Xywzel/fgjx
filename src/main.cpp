#include "Game.h"
#include "Morse.h"
#include <iostream>

int main(int argc, char** argv)
{
	//Game game;
	//game.run();

    std::string testString = "HELLO WORLD";
    std::cout << Morse::encode(testString) << std::endl;
    return 0;
}
