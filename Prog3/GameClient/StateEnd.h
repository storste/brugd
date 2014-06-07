#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"

class StateEnd :
	public GameState {
public:
	StateEnd();
	~StateEnd();

	void HandleEvents() override;
	void update(int ticks) override;
	void render() override;
	void CheckTransition() override;


	void RenderScore();

private:

};

