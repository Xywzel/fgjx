#include "Player.h"

float Player::getX()
{
	return playerX;
}

float Player::getY()
{
	return playerY;
}

void Player::render(SDL_Renderer* renderer)
{
	if(!avatar.ready)
	{
		avatar.init(renderer, "player.png");
	}
	avatar.render(playerX, playerY);
}
