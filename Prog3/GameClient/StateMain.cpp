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

void StateMain::CheckTransition(){

	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_P))
	{
//		GameEngine::getInstance()->getStateManager()->set_next_state(STATE_PAUSE);
		GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->_gameStates[STATE_PAUSE]);
	}

}


void StateMain::HandleEvents(){
	GameEngine::getInstance()->getInputHandler()->Update();
}

void StateMain::Update(int dt){
	for (auto& o : objects){
		o->Update(dt);
	}

}

void StateMain::Render(){
	SDL_SetRenderDrawColor(GameEngine::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(GameEngine::getInstance()->getRenderer());

	for (const auto& o : objects){
		o->Render();
	}

	SDL_RenderPresent(GameEngine::getInstance()->getRenderer());
}
