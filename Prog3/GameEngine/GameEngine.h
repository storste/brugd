#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <vector>
#include <list>
#include "GameObject.h"
#include "InputHandler.h"
#include <iostream>
#include "StateManager.h"

class GameEngine {

public:

	static GameEngine* getInstance();

	SDL_Renderer* getRenderer();
	StateManager* getStateManager();

	void render();
	void renderScore();
	void handleEvents();

	void quit();
	void run();

	const bool cd(GameObject *a, GameObject *b);

	InputHandler* getInputHandler(){ return InputHandler::Instance(); }
	
	TTF_Font* font = nullptr;
	int score;

private:

	GameEngine::GameEngine(int width = 640, int height = 480);
	~GameEngine();

	StateManager*		_stateManager;
	//InputHandler* _inputHandler;

	const int FPS = 60;
	const int tickInterval = 1000 / FPS;
	Uint32 nextTick = 0;
	int delay = 0;

	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;

	bool ttf_init = false;
	int screen_height = 640;
	int screen_width = 480;
	bool running = false;
};

