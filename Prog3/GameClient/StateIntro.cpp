#include "StateIntro.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"

StateIntro::StateIntro() {
	//std::cout << "Intro state constructor" << std::endl;
	m_world = GameEngine::getInstance();
}

StateIntro::~StateIntro() {
	//std::cout << "Intro state destructor" << std::endl;
}

void StateIntro::checkTransition(){
	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState("STATE_MAIN"));
	}
}

void StateIntro::update(int ticks){

}

