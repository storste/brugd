#include "StateManager.h"
#include "..\GameClient\MainState.h"
#include "..\GameClient\IntroState.h"
#include <iostream>

StateManager::StateManager()
{
	std::cout << "Creating state manager" << std::endl;
}


StateManager::~StateManager()
{
}

void StateManager::changeState(){

	if (nextState != STATE_NULL)
	{
		if (nextState != STATE_EXIT)
		{
			delete currentState;
		}

		//Change the state
		switch (nextState)
		{
			case STATE_MAIN:
				std::cout << "changing to main state" << std::endl;
				currentState = _gameStates["stateMain"];
				break;
			case STATE_INTRO:
				std::cout << "changing to intro state" << std::endl;
				currentState = _gameStates["stateIntro"];
				break;

		}
		stateID = nextState;

		nextState = STATE_NULL;
	}

}