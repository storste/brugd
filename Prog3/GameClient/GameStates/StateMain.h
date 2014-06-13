#ifndef STATEMAIN_H
#define STATEMAIN_H	
#include "../../GameEngine/GameState.h"

class StateMain :
	public GameState {
public:
	StateMain(int level);
	void checkTransition() override;

private:
	
};

#endif