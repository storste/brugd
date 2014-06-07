#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"

class StatePause :
	public GameState {
public:
	StatePause();
	~StatePause();

	void HandleEvents() override;
	void update(int ticks) override;
	void render() override;
	void CheckTransition() override;

private:
	
};

