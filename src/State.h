#pragma once

class PauseMenu;
class MainMenu;
class ScoreScreen;
class Level;
struct SDL_Renderer;
union SDL_Event;

class State {
	public:
		State();
		~State();
		void handleEvent(SDL_Event &e);
		void update(float deltaTime);
		void render(SDL_Renderer* renderer);
		bool gameOver();
	private:
		void startGame();
		void nextLevel();
		bool inMainMenu;
		bool inPauseMenu;
		bool inScoreScreen;
		bool inLevel;
		int levelNumber;
		int score;
		MainMenu* mainMenu;
		PauseMenu* pauseMenu;
		ScoreScreen* scoreScreen;
		Level* level;
};
