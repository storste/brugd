#pragma once
#include "GameState.h"
#include <map>

enum State {
	STATE_NULL,
	STATE_INTRO,
	STATE_MAIN,
	STATE_PAUSE,
	STATE_END,
	STATE_EXIT
};

class StateManager {

public:
	StateManager();
	~StateManager();

	void addGameState(State stateID, GameState* state){
		std::pair<State, GameState*> pair = std::make_pair(stateID, state);
		_gameStates.insert(pair);
	};

	void setCurrentState(GameState *state){ _currentState = state; }

	GameState* getCurrentState() { return _currentState; }
	GameState* getState(State stateID) { return _gameStates[stateID]; }

	//void changeState();
	//void set_next_state(int newState){ nextState = newState; }

	//int stateID = STATE_NULL;
	//int nextState = STATE_NULL;

private:
	GameState* _currentState;
	std::map<State, GameState*> _gameStates;
};

