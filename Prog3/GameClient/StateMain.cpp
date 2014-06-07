#pragma once
#include "StateMain.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"

StateMain::StateMain()
{
	_world = GameEngine::getInstance();
	std::cout << "Main state Constructor" << std::endl;
}

StateMain::~StateMain()
{
	std::cout << "Main state destructor" << std::endl;

}

void StateMain::CheckTransition(){

	if (_world->getInputHandler()->isKeyDown(SDL_SCANCODE_P))
	{
		_world->getStateManager()->setCurrentState(_world->getStateManager()->getState(STATE_PAUSE));
	}

	if (_world->getInputHandler()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		_world->getStateManager()->setCurrentState(_world->getStateManager()->getState(STATE_END));
	}

}

void StateMain::handleEvents(){
	_world->getInputHandler()->Update();
}

void StateMain::update(int dt){

	for (std::list<GameObject*>::iterator itr = _objects.begin(); itr != _objects.end();)
	{
		if ((*itr)->is_visible() == false){
			std::cout << (*itr)->getName() << " is not visible" << std::endl;
			delete (*itr);
			itr = _objects.erase(itr);
		}
		else{
			++itr;
		}

	}

	for (auto& o : _objects){
		o->Update(dt);
	}
}

void StateMain::render(){
	SDL_SetRenderDrawColor(_world->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_world->getRenderer());

	for (const auto& o : _objects){
		o->render();
	}

	renderScore();

	SDL_RenderPresent(_world->getRenderer());
}


void StateMain::renderScore(){

	std::string score_text = "score: " + std::to_string(_world->score);
	SDL_Color textColor = { 255, 255, 255, 0 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(_world->font, score_text.c_str(), textColor);
	SDL_Texture* text = SDL_CreateTextureFromSurface(_world->getRenderer(), textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	SDL_Rect clearQuad = { 20, 50 - 30, text_width + 30, text_height };
	SDL_Rect renderQuad = { 20, 50 - 30, text_width, text_height };
	SDL_SetRenderDrawColor(_world->getRenderer(), 0, 0, 0, 0);
	SDL_RenderFillRect(_world->getRenderer(), &clearQuad);

	SDL_RenderCopy(_world->getRenderer(), text, NULL, &renderQuad);
	SDL_DestroyTexture(text);
}