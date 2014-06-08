#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"

class StatePause :
	public GameState {
public:

	StatePause();
	~StatePause();

	void checkTransition() override;
	
private:
	
};

