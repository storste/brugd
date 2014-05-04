#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "GameEngine.h"

void GameEngine::run(){

	running = true;

	while (running)
	{
		handleEvents();
		update();
		render();
	}
	//g_game->clean();

}

void GameEngine::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
		}
	}
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

void GameEngine::render_dot(){
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	if (!getRenderer())
		std::cout << "No renderer..." << std::endl;

	// lite irriterande att path refererar till Game och inte GameEngine här...
	SDL_Texture* golddot = IMG_LoadTexture(getRenderer(), "../GameEngine/golddot.png");
	if (!golddot)
		std::cout << "Image failed to load" << std::endl;

	SDL_Rect src;
	src.h = 32; src.w = 32;
	SDL_Rect dst;
	dst.h = 32; dst.w = 32;
	src.x = 1 * 32;

	for (int i = 0; i < 15; ++i){
		for (int j = 0; j < 20; ++j){
			dst.x = j * 32; dst.y = i * 32;
			SDL_RenderCopyEx(getRenderer(), golddot, NULL /*&src*/, &dst, 0.0, NULL, SDL_FLIP_NONE);
		}
		src.y = i * 32;
	}


	//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	std::cout << "Rendering dot" << std::endl;
	SDL_RenderPresent(getRenderer());
	SDL_Delay(2000);
}



//SDL_Renderer* gRenderer;
//SDL_Surface* createSurface();
//static SDL_Window* window = nullptr;


TTF_Font *gFont = NULL;


void GameEngine::render_grid_dots(){
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	for (int i = 0, z = 0; i < 15; ++i){
		for (int j = 0; j < 20; ++j, ++z){


			//Set rendering space and render to screen
			SDL_Rect renderQuad = { j * 32, i * 32, 32, 32 };

			//Render to screen
			SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
			SDL_RenderDrawPoint(renderer, j * 32, i * 32);
		}
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);

}