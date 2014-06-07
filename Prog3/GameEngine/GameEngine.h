#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <vector>
#include <list>
#include "GameObject.h"
#include "StateManager.h"
#include "InputHandler.h"

class GameEngine {

public:

	static GameEngine* getInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new GameEngine();
		}
		return _instance;
	}

	SDL_Renderer* getRenderer()
	{
		return _renderer;
	}

	StateManager* getStateManager()
	{
		return _stateManager;
	}


	//void addGameObject(GameObject* d);
	//void removeGameObject(GameObject* d);
	//void render();
	//void update(int dt);
	//void HandleEvents();
	//Uint8* getKeyStates();

	void quit();
	void run();

	const bool cd(GameObject *a, GameObject *b);

	//std::vector<GameObject*> getObjects(){ return objects; }
	InputHandler* getInputHandler(){ return InputHandler::Instance(); }
	void setResolution(int w, int h);
	TTF_Font* font = nullptr;
	int score;

private:

	GameEngine::GameEngine(int width = 640, int height = 480);
	~GameEngine();

	static GameEngine*	_instance;
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

