#ifndef STATEINTRO_H
#define STATEINTRO_H	

#include "../../GameEngine/GameState.h"

class StateIntro :
	public GameState {
public:
	StateIntro();
	void checkTransition() override;
	
private:

};

#endif