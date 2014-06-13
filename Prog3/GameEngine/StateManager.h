#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "GameState.h"
#include <map>

class StateManager {

public:
	StateManager();
	~StateManager();

	void addGameState(const std::string stateID, GameState* state);

	void setCurrentState(GameState *state);

	GameState* getCurrentState();
	GameState* getState(std::string stateID);

private:
	GameState* m_currentState;
	std::map<std::string, GameState*> m_gameStates;
};

#endif