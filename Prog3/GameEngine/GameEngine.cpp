#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "GameEngine.h"

GameEngine* GameEngine::getInstance(){
	static GameEngine instance;
	return &instance;
	//if (_instance == nullptr)
	//{
	//	_instance = new GameEngine();
	//}
	//return _instance;
}

GameEngine* GameEngine::getInstance(int screenWidth, int screenHeight, int fps){
	static GameEngine instance;
	return &instance;
}


SDL_Renderer* GameEngine::getRenderer()
{
	return _renderer;
}

StateManager* GameEngine::getStateManager()
{
	return _stateManager;
}

void GameEngine::run(){

	//std::cout << "GameEngine: Run" << std::endl;

	running = true;

	while (running)
	{
		////std::cout << "GameEngine: tick " << nextTick << std::endl;

		nextTick = SDL_GetTicks() + tickInterval;

		handleEvents();
		_stateManager->getCurrentState()->update(nextTick);
		_stateManager->getCurrentState()->checkTransition();
		render();

		delay = nextTick - SDL_GetTicks();
		if (delay > 0){
			SDL_Delay(delay);
		}
			
	}
}

void GameEngine::quit()
{
	//std::cout << "GameEngine: Quit" << std::endl;
	running = false;
}

void GameEngine::handleEvents()
{
	InputHandler::Instance()->update();	
	for (const auto& keys : _stateManager->getCurrentState()->getKeyMap()){
		if (InputHandler::Instance()->isKeyDown(keys.first)){
			_stateManager->getCurrentState()->getKeyMap()[keys.first]();
		}
	}

}

void GameEngine::render(){

	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer);	

	for (const auto& o : _stateManager->getCurrentState()->getObjects())
		o->render();
	
	//renderScore();

	SDL_RenderPresent(_renderer);
}


void GameEngine::renderScore(){

	GameEngine* world = GameEngine::getInstance();

	std::string score_text = "score: " + std::to_string(world->score);
	SDL_Color textColor = { 255, 255, 255, 0 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(world->font, score_text.c_str(), textColor);
	SDL_Texture* text = SDL_CreateTextureFromSurface(world->getRenderer(), textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	SDL_Rect clearQuad = { 20, 50 - 30, text_width + 30, text_height };
	SDL_Rect renderQuad = { 20, 50 - 30, text_width, text_height };
	SDL_SetRenderDrawColor(world->getRenderer(), 0, 0, 0, 0);
	SDL_RenderFillRect(world->getRenderer(), &clearQuad);

	SDL_RenderCopy(world->getRenderer(), text, NULL, &renderQuad);
	SDL_DestroyTexture(text);
}

GameEngine::GameEngine(int width, int height) : screen_width(width), screen_height(height)
{
	//std::cout << "GameEngine: Constructor" << std::endl;
	//std::cout << FPS << std::endl;
	//std::cout << tickInterval << std::endl;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		//std::cout << "SDL inititalized" << std::endl;
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
		//std::cout << "SDL_image inititalized" << std::endl;
	}

	if ((TTF_Init() < 0)) { //std::cout << "could not initialize sdl_ttf" << std::endl; 
		exit(1); }
	font = TTF_OpenFont("assets/comic.ttf", 28);
	if (font == NULL) { //std::cout << "could not load font" << std::endl; 
		exit(1); }

	_stateManager = new StateManager();

}

GameEngine::~GameEngine()
{
	//std::cout << "GameEngine: Destructor" << std::endl;

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);

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

int GameEngine::getScreenWidth() {
	return screen_width;
}

int GameEngine::getScreenHeight() {
	return screen_height;
}


