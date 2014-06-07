#include "StateIntro.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"

StateIntro::StateIntro() {
	std::cout << "Intro state constructor" << std::endl;
	_world = GameEngine::getInstance();
}

StateIntro::~StateIntro() {
	std::cout << "Intro state destructor" << std::endl;
}

void StateIntro::CheckTransition(){
	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_RETURN))
	{		
		GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState(STATE_MAIN));
	}
}

void StateIntro::HandleEvents() {
	InputHandler::Instance()->update();
}

void StateIntro::update(int dt){
	for (const auto& o : _objects) {
		o->update(dt);
	}
}

void StateIntro::render(){

	SDL_SetRenderDrawColor(GameEngine::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(GameEngine::getInstance()->getRenderer());

	for (const auto& o : _objects) { o->render(); }

	SDL_RenderPresent(GameEngine::getInstance()->getRenderer());
}
