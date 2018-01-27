#pragma once
#include <SDL2/SDL.h>

class Player;
class Object;

class Level
{
    SDL_Texture* background = NULL;
	SDL_Renderer* renderer = NULL;
	public:
        Level();
        ~Level();
		virtual void update(); // Update level and all objects on it 
		virtual void render(SDL_Window* window); // Draw level and all object on it
		virtual int getScoreIncrease(); // If we keep score, change since last call

		virtual bool menuOpened(); // Has player asked to open pause menu, clear on check
		virtual bool finished(); // Level is completed and next one should be started
		virtual bool isGameOver(); // Level has failed and game should end

		static Level createLevel(int level); // Returns new level

};
