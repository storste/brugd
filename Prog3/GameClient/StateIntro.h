#pragma once
#include "..\GameEngine\GameState.h"

// forward declaration
class GameObject;

class StateIntro :
	public GameState {
public:
	StateIntro();
	~StateIntro();

	void handleEvents() override;
	void update(int ticks) override;
	void render() override;
	void checkTransition() override;

private:

};

