#pragma once

class PauseMenu;
class MainMenu;
class ScoreScreen;
class Level;

class State {
	public:
		State();
		~State();
		void update(float deltaTime);
		void render();
		bool gameOver();
	private:
		void startGame();
		void nextLevel();
		bool inMainMenu = true;
		bool inPauseMenu = false;
		bool inLevel = false;
		bool inScoreScreen = false;
		int levelNumber = 0;
		int score = 0;
		MainMenu& mainMenu;
		PauseMenu& pauseMenu;
		ScoreScreen& scoreScreen;
		Level& level;
};
