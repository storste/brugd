#pragma once
#include "..\GameEngine\GameState.h"

// forward declaration
class GameObject;

class StateIntro :
	public GameState {
public:
	StateIntro();
	~StateIntro();

	void HandleEvents() override;
	void update(int ticks) override;
	void render() override;
	void CheckTransition() override;

private:

};

