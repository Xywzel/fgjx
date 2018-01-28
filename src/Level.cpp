#include "Level.h"

#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Morse.h"

Level::Level(std::string msg, std::vector<std::pair<float, float>> coords)
	: completed(false)
	, failed(false)
	, pause(false)
	, score(0)
	, counter(0.0f)
	, player()
	, doors()
	, signals()
	, message(msg)
{
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
	for(auto coord : coords){
		Object door(Object::Type::Door, coord.first, coord.second);
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
	for(uint32_t i = 0; i < doors.size(); ++i){
		float px, py, dx, dy;
		px = player.getX();
		py = player.getY();
		dx = doors[i].getX();
		dy = doors[i].getY();
		if(std::fabs(px - dx) + std::fabs(py - dy) < 0.2f)
		{
			if(i == 0)
			{
				completed = true;
				if(score == 0) score = 1;
			}
			else
			{
				failed = true;
			}
		}
	}
}

int Level::getScoreIncrease(){
	int val = score;
	score = 0;
	return val;
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

Level* Level::createLevel(int levelNumber)
{
	std::vector<std::pair<float, float>> coords;
	switch(levelNumber)
	{
		case 0:
			coords.push_back(std::pair<float, float>(0.1f, 0.1f));
			return new Level("FIND THE DOOR.", coords);
		case 1:
			coords.push_back(std::pair<float, float>(0.5f, 0.9f));
			coords.push_back(std::pair<float, float>(0.9f, 0.5f));
			return new Level("GO SOUHT.", coords);
		case 2:
			coords.push_back(std::pair<float, float>(0.1f, 0.9f));
			coords.push_back(std::pair<float, float>(0.9f, 0.9f));
			coords.push_back(std::pair<float, float>(0.9f, 0.1f));
			return new Level("SOUTH WEST I THINK.", coords);
		case 3:
			coords.push_back(std::pair<float, float>(0.1f, 0.1f));
			coords.push_back(std::pair<float, float>(0.1f, 0.9f));
			coords.push_back(std::pair<float, float>(0.9f, 0.9f));
			coords.push_back(std::pair<float, float>(0.9f, 0.1f));
			return new Level("NOW NORTH WEST.", coords);
		case 4:
			coords.push_back(std::pair<float, float>(0.9f, 0.5f));
			coords.push_back(std::pair<float, float>(0.5f, 0.1f));
			coords.push_back(std::pair<float, float>(0.5f, 0.9f));
			coords.push_back(std::pair<float, float>(0.1f, 0.5f));
			return new Level("EAST DOOR USE THE EAST DOOR.", coords);
		case 5:
			coords.push_back(std::pair<float, float>(0.9f, 0.9f));
			coords.push_back(std::pair<float, float>(0.9f, 0.5f));
			coords.push_back(std::pair<float, float>(0.9f, 0.1f));
			coords.push_back(std::pair<float, float>(0.1f, 0.1f));
			coords.push_back(std::pair<float, float>(0.1f, 0.5f));
			coords.push_back(std::pair<float, float>(0.1f, 0.9f));
			return new Level("ALMOST THERE  USE THE SOUTH EAST DOOR .", coords);
		default:
			return new Level("FIND THE DOOR.", coords);
	}
}
