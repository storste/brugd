#include "MainState.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"
#include "..\GameEngine\InputHandler.h"

MainState::MainState()
{
	std::cout << "Main state Constructor" << std::endl;
}

MainState::~MainState()
{
	std::cout << "Main state destructor" << std::endl;

}

void MainState::handleEvents(){
	//std::cout << "Main state handle events" << std::endl;

	InputHandler::Instance()->update();
}

void MainState::update(int dt){
	for (auto& o : objects){
		o->update(dt);
	}
}

void MainState::render(){
	SDL_SetRenderDrawColor(GameEngine::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(GameEngine::getInstance()->getRenderer());

	for (const auto& o : objects){
		o->render();
	}

	SDL_RenderPresent(GameEngine::getInstance()->getRenderer());
}
