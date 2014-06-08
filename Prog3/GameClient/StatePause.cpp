#pragma once
#include <iostream>
#include "..\GameEngine\GameEngine.h"
#include "StatePause.h"

StatePause::StatePause()
{
	//std::cout << "StatePause: Constructor" << std::endl;
}

StatePause::~StatePause()
{
	//std::cout << "StatePause: Destructor" << std::endl;
}

void StatePause::checkTransition(){

	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_RETURN))
	{		
		GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState("STATE_MAIN"));
	}

	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState("STATE_END"));
	}
}


