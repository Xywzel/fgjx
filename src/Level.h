#pragma once
#include "LTexture.h"
#include <vector>

struct SDL_Texture;
struct SDL_Renderer;
union SDL_Event;

class Player;
class Object;

class Level
{
	LTexture background;
	bool completed;
	bool failed;
	std::vector<Object> doors;
	Player player;
	std::string message;
	public:
		Level();
		virtual ~Level();
		virtual void handleEvent(SDL_Event& /*e*/){}
		virtual void update(float deltaTime); // Update level and all objects on it 
		virtual void render(SDL_Renderer* renderer); // Draw level and all object on it
		virtual int getScoreIncrease(); // If we keep score, change since last call

		virtual bool menuOpened(); // Has player asked to open pause menu, clear on check
		virtual bool finished(); // Level is completed and next one should be started
		virtual bool isGameOver(); // Level has failed and game should end

		static Level* createLevel(int level); // Returns new level
};
