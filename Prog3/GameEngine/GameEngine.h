#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <vector>
#include "GameObject.h"
#include "StateManager.h"
#include "InputHandler.h"

class GameEngine {

public:

	static GameEngine* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameEngine();
		}
		return instance;
	}

	SDL_Renderer* getRenderer(){ return renderer; }

	StateManager* getStateManager(){
		return _stateManager;
	}


	void addGameObject(GameObject* d);
	void removeGameObject(GameObject* d);
	void Render();
	void Update(int dt);
	void HandleEvents();
	Uint8* getKeyStates();
	void graph();
	void quit();
	void run();
	const bool cd(GameObject *a, GameObject *b);
	std::vector<GameObject*> getObjects(){ return objects; }
	InputHandler* getInputHandler(){ return InputHandler::Instance(); }
	void setResolution(int w, int h);

private:

	static GameEngine* instance;
	StateManager* _stateManager;
	//InputHandler* _inputHandler;

	std::vector<GameObject*> objects;

	bool init();
	void handleInput();
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool ttf_init;
	int screen_height;
	int screen_width;
	bool running;
	GameEngine::GameEngine(int width = 640, int height = 480);
	Uint8* currentKeyStates;
	~GameEngine();
};

