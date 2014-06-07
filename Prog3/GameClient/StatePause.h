#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"

class StatePause :
	public GameState {
public:
	StatePause();
	~StatePause();

	void HandleEvents() override;
	void Update(int ticks) override;
	void Render() override;
	void CheckTransition() override;

private:
	
};

