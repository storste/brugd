#include "StateManager.h"
#include <iostream>

StateManager::StateManager() { std::cout << "StateManager: Constructor" << std::endl; }
StateManager::~StateManager() { std::cout << "StateManager: Destructor" << std::endl; }

//void StateManager::changeState(){
//
//	if (nextState != STATE_NULL)
//	{
//		if (nextState != STATE_EXIT)
//		{
//			//delete currentState;
//		}
//
//		switch (nextState)
//		{
//			case STATE_MAIN:
//				std::cout << "StateManager: Change to Main State" << std::endl;
//				currentState = _gameStates[STATE_MAIN];
//				break;
//			case STATE_INTRO:
//				std::cout << "StateManager: Change to Intro State" << std::endl;
//				currentState = _gameStates[STATE_INTRO];
//				break;
//			case STATE_PAUSE:
//				std::cout << "StateManager: Change to Pause State" << std::endl;
//				currentState = _gameStates[STATE_PAUSE];
//				break;
//		}
//
//		stateID = nextState;
//		nextState = STATE_NULL;
//	}
//}