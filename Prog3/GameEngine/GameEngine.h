#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "GameObject.h"
#include "InputHandler.h"
#include <iostream>
#include "StateManager.h"

class GameEngine {

public:

	static GameEngine* getInstance();
	static GameEngine* getInstance(int screenWidth, int screenHeight, int fps);

	SDL_Renderer* getRenderer();
	StateManager* getStateManager();

	void render();
	void handleEvents();

	void quit();
	void run();

	const bool cd(GameObject *a, GameObject *b);

	InputHandler* getInputHandler(){ return InputHandler::Instance(); }

	

	int getScreenWidth();
	int getScreenHeight();
	int getCanvasHeight();

	int getScore();
	void addToScore(int addend);

	TTF_Font* getFont() const;

private:
	static GameEngine* instance;

	GameEngine(int width = 640, int height = 480, int fps = 60);
	~GameEngine();

	StateManager*	m_stateManager;
	InputHandler*	m_inputHandler;

	int fps = 60;
	const int tickInterval = 1000 / fps;
	Uint32 nextTick = 0;
	int delay = 0;

	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;

	bool ttf_init = false;
	TTF_Font* font = nullptr;

	int screen_width = 640;
	int screen_height = 480;
	const int canvas_height = screen_height + 100;
	bool running = false;
	int m_score = 0;
};

#endif