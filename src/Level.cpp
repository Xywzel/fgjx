#include "Level.h"
#include "Morse.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <iostream>


Level::Level()
	: completed(false)
	, failed(false)
	, pause(false)
	, counter(0.0f)
	, player()
	, doors()
	, signals()
{
	message = "NO FUCKING CLUE.";
	//Initialize SDL_mixer
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		std::cout <<  "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
	}
	//Load music
	music = Mix_LoadMUS( "noise.wav" );
	if( music == NULL )
	{
		std::cout << "Failed to load beat music! SDL_mixer Error: " << Mix_GetError() << std::endl;
	}
	morseCode = Morse::encode(message);
	for (std::string::iterator it=morseCode.begin(); it!=morseCode.end();++it)
	{
		switch(*it)
		{
			case '.':
				signals.push(Morse::dot);
				break;
			case '-':
				signals.push(Morse::dash);
				break;
			case ' ':
				signals.push(Morse::pause);
				break;
			default:
				break;
		}
	}
	// Place level objects
	{
		Object door(Object::Type::Door, 0.1f, 0.1f);
		doors.push_back(door);
	}
	{
		Object door(Object::Type::Door, 0.9f, 0.9f);
		doors.push_back(door);
	}
}

Level::~Level()
{
	Mix_HaltMusic();
	Mix_FreeMusic(music);
	music = NULL;
}

void Level::handleEvent(SDL_Event& e)
{
	if(e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.sym)
		{
			case SDLK_ESCAPE:
				pause = true;
				return;
		}
	}
	player.handleEvent(e);
}

void Level::update(float deltaTime)
{
	if( Mix_PlayingMusic() == 0 )
	{
		//Play the noise
		Mix_PlayMusic( music, -1 );
	}
	counter -= deltaTime;
	if(counter <= 0.0f){
		if(!signals.empty()){
			counter = signals.front();
			signals.pop();
		}
		//If the noise is paused
		if( Mix_PausedMusic() == 1 )
		{
			//Resume the noise
			Mix_ResumeMusic();
		}
	}
	else
	{
		if( Mix_PausedMusic() == 0 ){
			//Pause the noise
			Mix_PauseMusic();
		}
	}
	player.update(deltaTime);
	for(auto door : doors)
		door.update(deltaTime);
	{
		float px, py, dx, dy;
		px = player.getX();
		py = player.getY();
		dx = doors[0].getX();
		dy = doors[0].getY();
		if((px - dx) + (py - dy) < 0.2f)
			completed = true;
	}
}

int Level::getScoreIncrease(){
	return 0;
}

bool Level::menuOpened(){
  bool val = pause;
  pause = false;
  return val;
}

bool Level::finished(){
    return completed;
}

bool Level::isGameOver(){
    return failed;
}

void Level::render(SDL_Renderer* renderer)
{
	if(!background.ready)
	{
		background.init(renderer, "board.png");
	}
	background.render(0,0, 1.0f, 1.0f);
	for(auto door : doors)
		door.render(renderer);
	player.render(renderer);
}

