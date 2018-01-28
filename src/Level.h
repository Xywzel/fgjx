#pragma once
#include <vector>
#include <string>
#include <queue>
#include <utility>

#include <SDL2/SDL_mixer.h>

#include "LTexture.h"
#include "Object.h"
#include "Player.h"

struct SDL_Texture;
struct SDL_Renderer;
union SDL_Event;

class Player;
class Object;

class Level
{
	public:
		Level(std::string msg, std::vector<std::pair<float, float>> coords);
		virtual ~Level();
		virtual void handleEvent(SDL_Event& e);
		virtual void update(float deltaTime); // Update level and all objects on it 
		virtual void render(SDL_Renderer* renderer); // Draw level and all object on it
		virtual int getScoreIncrease(); // If we keep score, change since last call

		virtual bool menuOpened(); // Has player asked to open pause menu, clear on check
		virtual bool finished(); // Level is completed and next one should be started
		virtual bool isGameOver(); // Level has failed and game should end

		static Level* createLevel(int level); // Returns new level
	private:
		bool completed;
		bool failed;
		bool pause;
		int score;
		float counter;
		Player player;
		std::vector<Object> doors;
		std::queue<float> signals;
		std::string message;
		std::string morseCode;
		Mix_Music* music;
		LTexture background;
};
