#ifndef STATEPAUSE_H
#define STATEPAUSE_H	
#include "../../GameEngine/GameState.h"

class StatePause :
	public GameState {
public:

	StatePause();
	~StatePause();

	void checkTransition() override;	
	
private:
	
};

#endif