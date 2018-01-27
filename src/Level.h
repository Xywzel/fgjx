#pragma once
#include <SDL2/SDL.h>

class Player;
class Object;

class Level
{
	SDL_Texture* background = NULL;
	bool completed;
	bool failed;
	public:
		Level();
		virtual ~Level();
		virtual void update(float deltaTime); // Update level and all objects on it 
		virtual void render(SDL_Renderer* renderer); // Draw level and all object on it
		virtual int getScoreIncrease(); // If we keep score, change since last call

		virtual bool menuOpened(); // Has player asked to open pause menu, clear on check
		virtual bool finished(); // Level is completed and next one should be started
		virtual bool isGameOver(); // Level has failed and game should end

		static Level* createLevel(int level); // Returns new level

};
