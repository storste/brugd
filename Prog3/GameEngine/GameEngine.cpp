#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "GameEngine.h"
//#include "InputHandler.h"
//#include "StateManager.h"

GameEngine* GameEngine::_instance;

void GameEngine::run(){

	std::cout << "GameEngine: Run" << std::endl;

	running = true;

	while (running)
	{
		//std::cout << "GameEngine: tick " << nextTick << std::endl;

		nextTick = SDL_GetTicks() + tickInterval;

		_stateManager->getCurrentState()->HandleEvents();
		_stateManager->getCurrentState()->update(nextTick);
		_stateManager->getCurrentState()->CheckTransition();
		_stateManager->getCurrentState()->render();

		delay = nextTick - SDL_GetTicks();
		if (delay > 0){
			SDL_Delay(delay);
		}
			
	}
}


void GameEngine::quit()
{
	std::cout << "GameEngine: Quit" << std::endl;

	running = false;
}

//void GameEngine::HandleEvents()
//{
//	InputHandler::Instance()->update();
//}
//
//void GameEngine::update(int dt)
//{
//	//for (std::vector<GameObject*>::iterator itr = objects.begin(); itr != objects.end();)
//	//{
//	//	if ((*itr)->is_visible() == false){
//
//	//		//delete (*itr);
//	//		//itr = objects.erase(itr);
//	//	}
//	//	else
//	//		++itr;
//	//}
//
//	for (auto& o : objects){
//		o->update(dt);
//	}
//}
//
//void GameEngine::addGameObject(GameObject* d){
//	objects.push_back(d);
//}
//
//void GameEngine::removeGameObject(GameObject* d){
//	d->set_visible();
//}
//
//void GameEngine::render(){
//
//	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	SDL_RenderClear(_renderer);
//
//	for (const auto& o : objects){
//		o->render();
//	}
//
//	SDL_RenderPresent(_renderer);
//}


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
		_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
		if (_window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}

		_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	else{
		std::cout << "SDL_image inititalized" << std::endl;
	}

	if ((TTF_Init() < 0)) { std::cout << "could not initialize sdl_ttf" << std::endl; exit(1); }
	font = TTF_OpenFont("assets/comic.ttf", 28);
	if (font == NULL) { std::cout << "could not load font" << std::endl; exit(1); }

	_stateManager = new StateManager();

}

GameEngine::~GameEngine()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	std::cout << "GameEngine: Destructor" << std::endl;

	//Quit TTF subsystems
	if (ttf_init)
		TTF_Quit();

	IMG_Quit();

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


void GameEngine::setResolution(int w, int h){

	std::cout << "Changing resolution to " << w << ":" << h << std::endl;

	// funkar inte eftersom texturerna är laddade till den gamla rendern, behöver ladda in alla texturer igen... suck

	//SDL_DestroyRenderer(_renderer);
	//SDL_DestroyWindow(_window);

	//_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	//if (_window == NULL)
	//{
	//	printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	//}

	//_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

}

