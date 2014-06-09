#pragma once
#include "..\..\GameEngine\GameState.h"

class StateIntro :
	public GameState {
public:
	StateIntro();
	void checkTransition() override;
	
private:

};

