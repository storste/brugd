#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "GameEngine.h"
#include "..\GameEngine\InputHandler.h"


GameEngine* GameEngine::instance;

void GameEngine::run(){

	running = true;

	while (running)
	{
		handleEvents();
		update();
		render();
	}

}


void GameEngine::quit()
{
	running = false;
}

void GameEngine::handleEvents()
{
	InputHandler::Instance()->update();
}

void GameEngine::update()
{
	for (auto& o : objects){
		o->update();
	}
}


void GameEngine::addDrawable(GameObject* d){
	objects.push_back(d);
}

void GameEngine::render(){

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	for (auto& o : objects){
		o->render();
	}
	SDL_RenderPresent(renderer);
	//SDL_Delay(2000);

}


GameEngine::GameEngine(int width, int height) : screen_width(width), screen_height(height)
{
	std::cout << "Running engine constructor" << std::endl;
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
}

GameEngine::~GameEngine()
{
	SDL_DestroyRenderer(renderer);
	std::cout << "Running engine destructor" << std::endl;
	//Quit TTF subsystems
	if (ttf_init)
		TTF_Quit();
	//Quit SDL subsystems
	SDL_Quit();

}




//SDL_Renderer* gRenderer;
//SDL_Surface* createSurface();
//static SDL_Window* window = nullptr;


TTF_Font *gFont = NULL;


