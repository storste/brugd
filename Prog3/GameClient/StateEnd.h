#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"

class StateEnd :
	public GameState {
public:
	StateEnd();
	~StateEnd();

	void HandleEvents() override;
	void Update(int ticks) override;
	void Render() override;
	void CheckTransition() override;


	void RenderScore();

private:

};

