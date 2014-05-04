#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <vector>
#include "GameObject.h"

class GameEngine{
public:
	static GameEngine* getEngineInstance()	{
		if (instance == 0)
		{
			instance = new GameEngine();
		}
		return instance;
	}

	

	SDL_Renderer* getRenderer(){ return renderer; }

	void addDrawable(GameObject* d);
	void render();	
	void update();
	void handleEvents();
	void graph();

	void run();


private:
	std::vector<GameObject*> objects;
	static GameEngine* instance;
	bool init();
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool ttf_init;
	int screen_height;
	int screen_width;
	bool running;
	GameEngine::GameEngine(int width = 640, int height = 480);
	~GameEngine();

};

