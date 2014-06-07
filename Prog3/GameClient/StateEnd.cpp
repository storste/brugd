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



void StateEnd::CheckTransition(){
	
}


void StateEnd::HandleEvents(){
	InputHandler::Instance()->Update();
}

void StateEnd::Update(int dt){

	

}

void StateEnd::Render(){

	SDL_SetRenderDrawColor(GameEngine::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(GameEngine::getInstance()->getRenderer());

	for (const auto& o : objects){
		o->Render();
	}

	RenderScore();

	SDL_RenderPresent(GameEngine::getInstance()->getRenderer());

	//SDL_Delay(3000);
	GameEngine::getInstance()->quit();

}


void StateEnd::RenderScore(){

	GameEngine* world = GameEngine::getInstance();
	
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