#pragma once
#include "..\GameEngine\GameState.h"

class StateMain :
	public GameState {
public:
	StateMain(int level);
	~StateMain();

	//void update(int ticks) override;
	void checkTransition() override;
	int getLevel(){ return m_level; }
private:
	int m_level = 0;
};

