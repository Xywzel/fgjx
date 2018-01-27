#include "Player.h"

float Player::getX()
{
	return playerX;
}

float Player::getY()
{
	return playerY;
}

void Player::setXY(float x , float y){
	playerX = x;
	playerY = y;
}

void Player::render(SDL_Renderer* renderer)
{
	if(!avatar.ready)
	{
		avatar.init(renderer, "player_idle.png");
	}
	avatar.render(playerX, playerY, 0.25, 0.25);
}

void Player::update(float deltaTime)
{
}
