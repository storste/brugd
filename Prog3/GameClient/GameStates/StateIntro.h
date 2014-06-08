#pragma once
#include "..\..\GameEngine\GameState.h"

class StateIntro :
	public GameState {
public:
	StateIntro();
	~StateIntro();
		
	void checkTransition() override;
	void exitState();
	void update(int ticks);

private:

};

