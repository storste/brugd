#include <iostream>
#include "StatePause.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Sprite.h"

StatePause::StatePause()
{
	//std::cout << "StatePause: Constructor" << std::endl;
	Image pauseImage("assets/pause.png", true);
	Sprite* pause_background = Sprite::getInstance(&pauseImage, "Intro background");
	pause_background->setPosition(0, 0);
	addGameObject(pause_background);
	getKeyMap()[SDL_SCANCODE_RETURN] = std::bind([](){ GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState("STATE_MAIN"));	});
	getKeyMap()[SDL_SCANCODE_ESCAPE] = std::bind([](){ GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState("STATE_END"));	});
}

StatePause::~StatePause()
{
	//std::cout << "StatePause: Destructor" << std::endl;
}

void StatePause::checkTransition(){

}
