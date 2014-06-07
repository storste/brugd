#pragma once
#include "StateMain.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"

StateMain::StateMain()
{
	world = GameEngine::getInstance(); 
	std::cout << "Main state Constructor" << std::endl;
}

StateMain::~StateMain()
{
	std::cout << "Main state destructor" << std::endl;

}

void StateMain::CheckTransition(){

	if (world->getInputHandler()->isKeyDown(SDL_SCANCODE_P))
	{
		world->getStateManager()->setCurrentState(world->getStateManager()->getState(STATE_PAUSE));
	}

	if (world->getInputHandler()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{		
		world->getStateManager()->setCurrentState(world->getStateManager()->getState(STATE_END));
	}

}

void StateMain::HandleEvents(){
	world->getInputHandler()->Update();
}

void StateMain::Update(int dt){

	for (std::list<GameObject*>::iterator itr = objects.begin(); itr != objects.end();)
	{
		if ((*itr)->is_visible() == false){
			std::cout << (*itr)->getName() << " is not visible" << std::endl;
			delete (*itr);
			itr = objects.erase(itr);
		}
		else
			++itr;
	}

	for (auto& o : objects){
		o->Update(dt);
	}
}

void StateMain::Render(){
	SDL_SetRenderDrawColor(world->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(world->getRenderer());

	for (const auto& o : objects){
		o->Render();
	}

	RenderScore();

	SDL_RenderPresent(world->getRenderer());
}


void StateMain::RenderScore(){
	
	std::string score_text = "score: " + std::to_string(world->score);
	SDL_Color textColor = { 255, 255, 255, 0 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(world->font, score_text.c_str(), textColor);
	SDL_Texture* text = SDL_CreateTextureFromSurface(world->getRenderer(), textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	SDL_Rect clearQuad = { 20, 50 - 30, text_width + 30, text_height };
	SDL_Rect renderQuad = { 20, 50 - 30, text_width, text_height };
	SDL_SetRenderDrawColor(world->getRenderer(), 0, 0, 0, 0);
	SDL_RenderFillRect(world->getRenderer(), &clearQuad);

	SDL_RenderCopy(world->getRenderer(), text, NULL, &renderQuad);
	SDL_DestroyTexture(text);
}