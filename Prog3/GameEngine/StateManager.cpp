#pragma once
#include "StateManager.h"
#include <iostream>

StateManager::StateManager() {
	//std::cout << "StateManager: Constructor" << std::endl;
}

StateManager::~StateManager() {
	//std::cout << "StateManager: Destructor" << std::endl;
}

void StateManager::addGameState(const std::string stateID, GameState* state){
	std::pair<const std::string, GameState*> pair = std::make_pair(stateID, state);
	m_gameStates.insert(pair);
}

void StateManager::setCurrentState(GameState *state){
	m_currentState = state;
}

GameState* StateManager::getCurrentState() {
	return m_currentState;
}

GameState* StateManager::getState(const std::string stateID) {
	return m_gameStates[stateID];
}