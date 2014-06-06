#include "StateMain.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"

StateMain::StateMain()
{
	std::cout << "Main state Constructor" << std::endl;
}

StateMain::~StateMain()
{
	std::cout << "Main state destructor" << std::endl;

}

void StateMain::handleEvents(){
	GameEngine::getInstance()->getInputHandler()->update();
}

void StateMain::update(int dt){
	for (auto& o : objects){
		o->update(dt);
	}

	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_P))
	{
		GameEngine::getInstance()->getStateManager()->set_next_state(STATE_PAUSE);
	}

}

void StateMain::render(){
	SDL_SetRenderDrawColor(GameEngine::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(GameEngine::getInstance()->getRenderer());

	for (const auto& o : objects){
		o->render();
	}

	SDL_RenderPresent(GameEngine::getInstance()->getRenderer());
}
