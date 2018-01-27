#pragma once

class PauseMenu;
class MainMenu;
class ScoreScreen;
class Level;
struct SDL_Renderer;

class State {
	public:
		State();
		~State();
		void update(float deltaTime);
		void render(SDL_Renderer* renderer);
		bool gameOver();
	private:
		void startGame();
		void nextLevel();
		bool inMainMenu;
		bool inPauseMenu;
		bool inLevel;
		bool inScoreScreen;
		int levelNumber;
		int score;
		MainMenu* mainMenu;
		PauseMenu* pauseMenu;
		ScoreScreen* scoreScreen;
		Level* level;
};
