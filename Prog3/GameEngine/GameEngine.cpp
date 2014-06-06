#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "GameEngine.h"
#include "InputHandler.h"
#include "StateManager.h"

#define FPS 60
GameEngine* GameEngine::instance;

const int tickInterval = 1000 / FPS;
Uint32 nextTick;
int delay;

void GameEngine::setResolution(int w, int h){

	std::cout << "Changing resolution to " << w << ":" << h << std::endl;

	// funkar inte eftersom texturerna är laddade till den gamla rendern, behöver ladda in alla texturer igen... suck
	
	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyWindow(window);

	//window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	//if (window == NULL)
	//{
	//	printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	//}

	//renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

void GameEngine::run(){

	std::cout << "GameEngine: Run" << std::endl;

	running = true;

	while (running)
	{
		nextTick = SDL_GetTicks() + tickInterval;

		_stateManager->getCurrentState()->HandleEvents();
		_stateManager->getCurrentState()->Update(nextTick);
		_stateManager->getCurrentState()->CheckTransition();
		_stateManager->getCurrentState()->Render();

		delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}
}


void GameEngine::quit()
{
	std::cout << "GameEngine: Quit" << std::endl;

	running = false;
}

void GameEngine::HandleEvents()
{
	InputHandler::Instance()->Update();
}

void GameEngine::Update(int dt)
{
	//for (std::vector<GameObject*>::iterator itr = objects.begin(); itr != objects.end();)
	//{
	//	if ((*itr)->is_visible() == false){

	//		//delete (*itr);
	//		//itr = objects.erase(itr);
	//	}
	//	else
	//		++itr;
	//}

	for (auto& o : objects){
		o->Update(dt);
	}
}

void GameEngine::addGameObject(GameObject* d){
	objects.push_back(d);
}

void GameEngine::removeGameObject(GameObject* d){
	d->set_visible();
}

void GameEngine::Render(){

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	for (const auto& o : objects){
		o->Render();
	}

	SDL_RenderPresent(renderer);
}


GameEngine::GameEngine(int width, int height) : screen_width(width), screen_height(height)
{
	std::cout << "GameEngine: Constructor" << std::endl;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << "SDL inititalized" << std::endl;
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	else{
		std::cout << "SDL_image inititalized" << std::endl;
	}

	_stateManager = new StateManager();

}

GameEngine::~GameEngine()
{
	SDL_DestroyRenderer(renderer);
	std::cout << "GameEngine: Destructor" << std::endl;
	//Quit TTF subsystems
	if (ttf_init)
		TTF_Quit();
	//Quit SDL subsystems
	SDL_Quit();

	delete _stateManager;
}

const bool GameEngine::cd(GameObject* a, GameObject* b)
{
	int left1, left2;
	int right1, right2;
	int top1, top2;
	int bottom1, bottom2;

	left1 = a->getX();
	left2 = b->getX();
	right1 = a->getX() + a->getW();
	right2 = b->getX() + b->getW();
	top1 = a->getY();
	top2 = b->getY();
	bottom1 = a->getY() + a->getH();
	bottom2 = b->getY() + b->getH();

	if (bottom1 <= top2)
	{
		return false;
	}

	if (top1 >= bottom2)
	{
		return false;
	}

	if (right1 <= left2)
	{
		return false;
	}

	if (left1 >= right2)
	{
		return false;
	}

	return true;
}


