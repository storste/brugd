#include "StateIntro.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"

StateIntro::StateIntro()
{
	std::cout << "Intro state constructor" << std::endl;
}

StateIntro::~StateIntro()
{
	std::cout << "Intro state destructor" << std::endl;
}

void StateIntro::handleEvents(){
	InputHandler::Instance()->update();
}

void StateIntro::update(int dt){
	for (auto& o : objects){
		o->update(dt);
	}

	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		GameEngine::getInstance()->getStateManager()->set_next_state(STATE_MAIN);
	}

}

void StateIntro::render(){
	SDL_SetRenderDrawColor(GameEngine::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(GameEngine::getInstance()->getRenderer());

	for (const auto& o : objects){
		o->render();
	}

	SDL_RenderPresent(GameEngine::getInstance()->getRenderer());
}
