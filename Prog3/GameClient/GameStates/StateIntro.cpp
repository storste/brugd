#include "StateIntro.h"
#include "..\..\GameEngine\GameEngine.h"
#include "..\..\GameEngine\Sprite.h"

StateIntro::StateIntro() {
	//std::cout << "Intro state constructor" << std::endl;
	m_world = GameEngine::getInstance();
	Image introImage("assets/intro.png", true);
	Sprite* intro_background = Sprite::getInstance(&introImage, "Intro background");
	intro_background->setPosition(0, 0);
	addGameObject(intro_background);
	getKeyMap()[SDL_SCANCODE_RETURN] = std::bind(&StateIntro::exitState, this);
}

StateIntro::~StateIntro() {
	std::cout << "Intro state destructor" << std::endl;
}

void StateIntro::checkTransition(){

	//if (GameEngine::getInstance()->getInputHandler()->isKeyDown(SDL_SCANCODE_RETURN))
	//{
	//	GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState("STATE_MAIN"));
	//	delete this;
	//}
}

void StateIntro::update(int ticks){

}

void StateIntro::exitState(){
	//delete this;
	GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState("STATE_MAIN"));
}