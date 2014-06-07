#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"
#include <iostream>

class StateMain :
	public GameState {
public:
	StateMain();
	~StateMain();

	void handleEvents() override;
	void update(int ticks) override;
	void render() override;
	void checkTransition() override;

	void StateMain::RenderScore();

private:

};

