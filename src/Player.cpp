#include "Player.h"
#include <algorithm>
#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

Player::Player()
	: x(0.5f)
	, y(0.5f)
	, xSpeed(0.0f)
	, ySpeed(0.0f)
{
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	float norm = (std::fabs(xSpeed) > 0.01f && std::fabs(ySpeed) > 0.01f) ? 0.707f : 1.0f;
	x += norm * xSpeed * deltaTime;
	y += norm * ySpeed * deltaTime;
}

void Player::render(SDL_Renderer* renderer)
{
	if(!avatar.ready)
	{
		avatar.init(renderer, "player_idle.png");
	}
	avatar.render(x, y, 0.1);
}

void Player::handleEvent(SDL_Event& e)
{
	if(e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.sym)
		{
			case SDLK_w:
				ySpeed = -0.1f;
				break;
			case SDLK_s:
				ySpeed = 0.1f;
				break;
			case SDLK_a:
				xSpeed = -0.1f;
				break;
			case SDLK_d:
				xSpeed = 0.1f;
				break;
		}
	}
	if(e.type == SDL_KEYUP)
	{
		switch(e.key.keysym.sym)
		{
			case SDLK_w:
				ySpeed = std::max(ySpeed, 0.0f);
				break;
			case SDLK_s:
				ySpeed = std::min(ySpeed, 0.0f);
				break;
			case SDLK_a:
				xSpeed = std::max(xSpeed, 0.0f);
				break;
			case SDLK_d:
				xSpeed = std::min(xSpeed, 0.0f);
				break;
		}
	}
}

float Player::getX()
{
	return x;
}

float Player::getY()
{
	return y;
}

void Player::setXY(float _x , float _y)
{
	x = _x;
	y = _y;
}

