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
	, mirror(false)
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
		avatar.init(renderer, "player.png");
		// first sprite
		spriteClips[0].x = 0;
		spriteClips[0].y = 0;
		spriteClips[0].w = 337;
		spriteClips[0].h = 512;
		// second sprite
		spriteClips[1].x = 338;
		spriteClips[1].y = 0;
		spriteClips[1].w = 362;
		spriteClips[1].h = 512;
	}

	if( ((int)(x*10)^(int)(y*11))&1 && (std::fabs(xSpeed) > 0.0f || std::fabs(ySpeed) > 0.0f))
	{
		avatar.render(x, y, 0.2, mirror, &spriteClips[1]);
	}
	else
	{
		avatar.render(x, y, 0.2, mirror, &spriteClips[0]);
	}
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
				mirror = true;
				break;
			case SDLK_d:
				xSpeed = 0.1f;
				mirror = false;
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

