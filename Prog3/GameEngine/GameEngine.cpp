#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "GameEngine.h"

GameEngine* GameEngine::instance;

GameEngine* GameEngine::getInstance(){
	if (instance == nullptr)
	{
		instance = new GameEngine();
	}
	return instance;
}

GameEngine* GameEngine::getInstance(int screenWidth, int screenHeight, int fps){
	if (instance == nullptr)
	{
		instance = new GameEngine(screenWidth, screenHeight, fps);
	}
	return instance;
}


SDL_Renderer* GameEngine::getRenderer()
{
	return m_renderer;
}

StateManager* GameEngine::getStateManager()
{
	return m_stateManager;
}

void GameEngine::run(){

	running = true;

	while (running)
	{
		nextTick = SDL_GetTicks() + tickInterval;

		handleEvents();
		m_stateManager->getCurrentState()->update(nextTick);
		m_stateManager->getCurrentState()->checkTransition();
		render();

		delay = nextTick - SDL_GetTicks();
		if (delay > 0){
			SDL_Delay(delay);
		}

	}
}

void GameEngine::quit()
{
	running = false;
}

void GameEngine::handleEvents()
{
	InputHandler::Instance()->update();
	for (const auto& keys : m_stateManager->getCurrentState()->getKeyMap()){
		if (InputHandler::Instance()->isKeyDown(keys.first)){
			m_stateManager->getCurrentState()->getKeyMap()[keys.first]();
		}
	}

}

void GameEngine::render(){

	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(m_renderer);

	for (const auto& o : m_stateManager->getCurrentState()->getObjects())
		o->render();

	SDL_RenderPresent(m_renderer);
}

GameEngine::GameEngine(int width, int height, int f) : screen_width(width), screen_height(height), fps(f)
{
	int seed = static_cast<int>(time(0));
	srand(seed);

	//std::cout << "GameEngine: Constructor" << std::endl;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		//std::cout << "SDL inititalized" << std::endl;
		m_window = SDL_CreateWindow("The worst Space Invaders game ever...",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, canvas_height, SDL_WINDOW_SHOWN);

		if (m_window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	}

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	else{
		//std::cout << "SDL_image inititalized" << std::endl;
	}

	if ((TTF_Init() < 0)) { //std::cout << "could not initialize sdl_ttf" << std::endl; 
		exit(1);
	}
	font = TTF_OpenFont("assets/comic.ttf", 28);
	if (font == NULL) { //std::cout << "could not load font" << std::endl; 
		exit(1);
	}

	m_stateManager = new StateManager();
	m_inputHandler = InputHandler::Instance();


}

GameEngine::~GameEngine()
{
	//std::cout << "GameEngine: Destructor" << std::endl;

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);

	//Quit TTF subsystems
	if (ttf_init)
		TTF_Quit();

	IMG_Quit();

	SDL_Quit();

	delete m_stateManager;
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

int GameEngine::getCanvasHeight() {
	return canvas_height;
}

int GameEngine::getScore(){
	return m_score;
}

void GameEngine::addToScore(int addend){
	m_score += addend;
}

TTF_Font* GameEngine::getFont() const{
	return font;
}