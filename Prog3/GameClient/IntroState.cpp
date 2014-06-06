#include "IntroState.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"
#include "..\GameEngine\InputHandler.h"

IntroState::IntroState()
{
	std::cout << "Intro state constructor" << std::endl;
}

IntroState::~IntroState()
{
	std::cout << "Intro state destructor" << std::endl;
}

void IntroState::handleEvents(){
	//std::cout << "Intro state handle events" << std::endl;
	InputHandler::Instance()->update();
}

void IntroState::update(int dt){
	for (auto& o : objects){
		o->update(dt);
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		GameEngine::getInstance()->getStateManager()->set_next_state(STATE_MAIN);
	}

}

void IntroState::render(){
	SDL_SetRenderDrawColor(GameEngine::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(GameEngine::getInstance()->getRenderer());

	for (const auto& o : objects){
		o->render();
	}

	SDL_RenderPresent(GameEngine::getInstance()->getRenderer());
}
