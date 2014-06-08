#include "..\GameEngine\GameEngine.h"
#include "..\GameEngine\MovingObject.h"
#include <stdlib.h>
#include <time.h>

#include "Player.h"
#include "Alien.h"
#include "AlienController.h"
#include "Missile.h"

#include "StateIntro.h"
#include "StateMain.h"
#include "StatePause.h"
#include "StateEnd.h"

// forward declarations
class Animation;
class Image;

int main(int argc, char *argv[])
{
	int seed = static_cast<int>(time(0));
	srand(seed);

	GameEngine* engine = GameEngine::getInstance();

	Animation alien_anim("assets/alien.png", 20, 19, 2, 2, 0);
	Animation alien_anim2("assets/alien2.png", 20, 20, 2, 2, 0);
	Animation tank("assets/tank.png", 70, 52, 7, 7, 0);
	Animation idle_tank("assets/tank.png", 70, 52, 1, 1, 58);
	Animation alienExp("assets/explosion3.png", 80, 80, 7, 5, 0);

	Player* player = Player::getInstance();
	player->addAnimation("run", &tank);
	player->addAnimation("idle", &idle_tank);
	player->setAnimation("run");
	player->setPosition(GameEngine::getInstance()->getWidth() / 2, GameEngine::getInstance()->getHeight() - 52);
	player->setName("Tank");

	AlienController* ac = new AlienController();
	Alien* alienArray[60];

	for (int i = 0; i < 15; i++) {
		alienArray[i] = Alien::getInstance("Alien");
		alienArray[i]->addAnimation("run", &alien_anim);
		alienArray[i]->addAnimation("explosion", &alienExp);
		alienArray[i]->setAnimation("run");
		alienArray[i]->setPosition(i * 30, 0);
	}
	for (int i = 0; i < 15; i++) {
		alienArray[i + 15] = Alien::getInstance("Alien");
		alienArray[i + 15]->addAnimation("run", &alien_anim2);
		alienArray[i + 15]->addAnimation("explosion", &alienExp);
		alienArray[i + 15]->setAnimation("run");
		alienArray[i + 15]->setPosition(i * 30, 30);
	}
	for (int i = 0; i < 15; i++) {
		alienArray[i + 30] = Alien::getInstance("Alien");
		alienArray[i + 30]->addAnimation("run", &alien_anim);
		alienArray[i + 30]->addAnimation("explosion", &alienExp);
		alienArray[i + 30]->setAnimation("run");
		alienArray[i + 30]->setPosition(i * 30, 60);
		}
	for (int i = 0; i < 15; i++) {
		alienArray[i + 45] = Alien::getInstance("Alien");
		alienArray[i + 45]->addAnimation("run", &alien_anim2);
		alienArray[i + 45]->addAnimation("explosion", &alienExp);
		alienArray[i + 45]->setAnimation("run");
		alienArray[i + 45]->setPosition(i * 30, 90);
	}
	
	



	// set up game states
	GameState *introState = new StateIntro();
	Image introImage("assets/intro.png", true);
	Sprite* intro_background = Sprite::getInstance(&introImage, "Intro background");
	intro_background->setPosition(0, 0);
	introState->addGameObject(intro_background);
	engine->getStateManager()->addGameState("STATE_INTRO", introState);

	GameState *pauseState = new StatePause();
	Image pauseImage("assets/pause.png", true);
	Sprite* pause_background = Sprite::getInstance(&pauseImage, "Intro background");
	pause_background->setPosition(0, 0);
	pauseState->addGameObject(pause_background);
	engine->getStateManager()->addGameState("STATE_PAUSE", pauseState);

	GameState *mainState = new StateMain(0);
	Image OrionImage("assets/Orion_Nebula.jpg", true);
	Sprite* main_background = Sprite::getInstance(&OrionImage, "Intro background");
	main_background->setPosition(0, 0);
	main_background->toggle_collidable();
	mainState->addGameObject(main_background);

	for (int i = 0; i < 60; i++) {
		mainState->addGameObject(alienArray[i]);
	}
	mainState->addGameObject(ac);
	mainState->addGameObject(player);
	engine->getStateManager()->addGameState("STATE_MAIN", mainState);


	GameState *endState = new StateEnd();
	engine->getStateManager()->addGameState("STATE_END", endState);

	engine->getStateManager()->setCurrentState(introState);
	

	engine->getStateManager()->getState("STATE_MAIN")->getKeyMap()[SDL_SCANCODE_SPACE] = std::bind(&Player::shoot, static_cast<Player*>(player));
	engine->getStateManager()->getState("STATE_MAIN")->getKeyMap()[SDL_SCANCODE_RIGHT] = std::bind(&Player::moveRight, static_cast<Player*>(player));
	engine->getStateManager()->getState("STATE_MAIN")->getKeyMap()[SDL_SCANCODE_LEFT] = std::bind(&Player::moveLeft, static_cast<Player*>(player));

	// run game
	engine->run();

	return (0);
}