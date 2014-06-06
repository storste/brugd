#include <iostream>
#include "..\GameEngine\GameEngine.h"
#include "StatePause.h"


StatePause::StatePause()
{
	std::cout << "StatePause: Constructor" << std::endl;
}

StatePause::~StatePause()
{
	std::cout << "StatePause: Destructor" << std::endl;
}

void StatePause::CheckTransition(){

	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		//GameEngine::getInstance()->getStateManager()->set_next_state(STATE_MAIN);
		GameEngine::getInstance()->getStateManager()->currentState = GameEngine::getInstance()->getStateManager()->_gameStates[STATE_MAIN];
	}
}


void StatePause::handleEvents(){
	InputHandler::Instance()->update();
}

void StatePause::update(int dt){

	for (const auto& o : objects){
		o->update(dt);
	}


	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		GameEngine::getInstance()->quit();
	}

}

void StatePause::render(){

	SDL_SetRenderDrawColor(GameEngine::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(GameEngine::getInstance()->getRenderer());

	for (const auto& o : objects){
		o->render();
	}

	SDL_RenderPresent(GameEngine::getInstance()->getRenderer());
}
