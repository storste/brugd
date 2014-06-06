#include "StateIntro.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"

StateIntro::StateIntro() { std::cout << "Intro state constructor" << std::endl; }
StateIntro::~StateIntro() { std::cout << "Intro state destructor" << std::endl; }

void StateIntro::CheckTransition(){
	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		//GameEngine::getInstance()->getStateManager()->set_next_state(STATE_MAIN);
		GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->_gameStates[STATE_MAIN]);
	}
}

void StateIntro::HandleEvents() { InputHandler::Instance()->Update(); }

void StateIntro::Update(int dt){
	for (auto& o : objects) { o->Update(dt); }
}

void StateIntro::Render(){

	SDL_SetRenderDrawColor(GameEngine::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(GameEngine::getInstance()->getRenderer());

	for (const auto& o : objects) { o->Render(); }

	SDL_RenderPresent(GameEngine::getInstance()->getRenderer());
}
