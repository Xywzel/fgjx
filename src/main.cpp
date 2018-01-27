#include "Game.h"
#include "Morse.h"
#include <iostream>

int main(int /*argc*/, char** /*argv*/)
{
	Game game;
	if(game.init())
		game.run();
}
