#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"
#include <iostream>

class StateMain :
	public GameState {
public:
	StateMain();
	~StateMain();

	void HandleEvents() override;
	void update(int ticks) override;
	void render() override;
	void CheckTransition() override;

	void StateMain::RenderScore();

private:

};

