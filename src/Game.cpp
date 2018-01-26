#include "Game.h"

Game::Game()
 : val(1)
{

}

Game::~Game(){}

void Game::run()
{
	val+=1;
}
