#include <iostream>
#include "StateEnd.h"
#include "../../GameEngine/GameEngine.h"
#include "../GameObjects/ScoreSprite.h"
#include "../GameObjects/TextSprite.h"

StateEnd::StateEnd()
{
	Image endImage("assets/end.png", true);
	Sprite* end_background = Sprite::getInstance(&endImage, "End background");
	end_background->setPosition(0, 0);
	addGameObject(end_background);

	ScoreSprite* score_sprite = new ScoreSprite();
	score_sprite->setPosition(0, 0);
	addGameObject(score_sprite);

	TextSprite* text_sprite = new TextSprite("Tack för att du spelade!", { 255, 192, 255, 0 }, { 255,255,255,0 });
	text_sprite->setPosition(200, 300);
	addGameObject(text_sprite);


	getKeyMap()[SDL_SCANCODE_RETURN] = std::bind([this](){ deleteState = true; });
}

StateEnd::~StateEnd()
{
	std::cout << "StateEnd: Destructor" << std::endl;
}

void StateEnd::checkTransition(){

}

void StateEnd::update(int dt){
	if (deleteState){
		SDL_Delay(500);
		GameEngine::getInstance()->quit();
	}
}
