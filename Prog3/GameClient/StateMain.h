#pragma once
#include "..\GameEngine\GameState.h"

class StateMain :
	public GameState {
public:
	StateMain();
	~StateMain();

	//void update(int ticks) override;
	void checkTransition() override;

private:

};

