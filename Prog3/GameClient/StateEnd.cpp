#include <iostream>
#include "..\GameEngine\GameEngine.h"
#include "StateEnd.h"


StateEnd::StateEnd()
{
	std::cout << "StateEnd: Constructor" << std::endl;
}

StateEnd::~StateEnd()
{
	std::cout << "StateEnd: Destructor" << std::endl;
}

void StateEnd::checkTransition(){
	
}

void StateEnd::update(int dt){
	GameEngine::getInstance()->quit();
}
