#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"

class StateEnd :
	public GameState {
public:
	StateEnd();
	~StateEnd();

	void handleEvents() override;
	void update(int ticks) override;
	void render() override;
	void checkTransition() override;


	void RenderScore();

private:

};

