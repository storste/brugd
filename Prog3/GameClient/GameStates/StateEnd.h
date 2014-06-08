#pragma once
#include "..\..\GameEngine\GameState.h"
#include "..\..\GameEngine\GameEngine.h"

class StateEnd :
	public GameState {
public:
	StateEnd();
	~StateEnd();

	void update(int ticks) override;
	void checkTransition() override;

private:

};

