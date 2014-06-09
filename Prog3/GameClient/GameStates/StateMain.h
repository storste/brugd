#pragma once
#include "..\..\GameEngine\GameState.h"
#include "..\..\GameEngine\GameEngine.h"

class StateMain :
	public GameState {
public:
	StateMain(int level);
	void checkTransition() override;

private:
	
};

