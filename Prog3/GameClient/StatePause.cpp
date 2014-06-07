#pragma once
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
		GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState(STATE_MAIN));
	}

	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_SPACE))
	{	
		GameEngine::getInstance()->setResolution(800, 600);
	}
}


void StatePause::HandleEvents(){
	InputHandler::Instance()->Update();
}

void StatePause::Update(int dt){

	for (const auto& o : _objects){
		o->Update(dt);
	}


	if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		GameEngine::getInstance()->quit();
	}

}

void StatePause::Render(){

	SDL_SetRenderDrawColor(GameEngine::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(GameEngine::getInstance()->getRenderer());

	for (const auto& o : _objects){
		o->Render();
	}

	SDL_RenderPresent(GameEngine::getInstance()->getRenderer());
}
