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
	void Update(int ticks) override;
	void Render() override;
	void CheckTransition() override;

private:

};

