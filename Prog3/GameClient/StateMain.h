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
	void Update(int ticks) override;
	void Render() override;
	void CheckTransition() override;

	void StateMain::RenderScore();

private:

};

