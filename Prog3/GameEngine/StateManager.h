#pragma once
#include "GameState.h"
#include <map>
#include <assert.h>

enum States
{
	STATE_NULL,
	STATE_INTRO,
	STATE_MAIN,
	STATE_PAUSE,
	STATE_EXIT
};


class StateManager
{
public:
	StateManager();
	~StateManager();

	void addGameState(int _stateName, GameState* state){
		std::pair<int, GameState*> pair = std::make_pair(_stateName, state);
		_gameStates.insert(pair);
	};

	std::map<int, GameState*> _gameStates;

	void setCurrentState(GameState *state){ currentState = state; }

	void changeState();
	GameState *currentState;
	void set_next_state(int newState){ nextState = newState; }

	int stateID = STATE_NULL;
	int nextState = STATE_NULL;
};

