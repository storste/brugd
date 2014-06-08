#include "..\GameEngine\GameEngine.h"
#include "..\GameEngine\MovingObject.h"

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
	GameEngine* engine = GameEngine::getInstance();

	Animation a("assets/dude.png", 130, 150, 27, 7, 0);
	Animation alien_anim("assets/alien.png", 20, 19, 2, 2, 0);
	Animation tank("assets/tank.png", 70, 52, 7, 7, 0);
	Animation idle_tank("assets/tank.png", 70, 52, 1, 1, 58);
	Animation alienExp("assets/explosion3.png", 80, 80, 7, 5, 0);

	AnimatedSprite* player = Player::getInstance();
	player->addAnimation("run", &tank);
	player->addAnimation("idle", &idle_tank);
	player->setAnimation("run");
	player->setPosition(GameEngine::getInstance()->getWidth() / 2, GameEngine::getInstance()->getHeight() - 52);
	//player->setName("Player");

	AlienController* ac = new AlienController();
	Alien* alienArray[50];

	//Image alien("assets/alien.jpg", true);
	for (int a = 0; a < 50; a += 5) {
		for (int b = 0; b < 5; b++) {
			alienArray[a + b] = Alien::getInstance("Alien");
			alienArray[a + b]->addAnimation("run", &alien_anim);
			alienArray[a + b]->addAnimation("explosion", &alienExp);
			alienArray[a + b]->setAnimation("run");
			alienArray[a + b]->setPosition((a * 6), b * 28);
		}
	}
	
	


	//Sprite* alien = new Alien(&pic, "Alien2");
	//alien->toggle_collidable();
	//alien.addAnimation("alien", &alien_anim);
	//alien.setAnimation("alien");

	//Sprite* test = new MovingObject("assets/poteto.bmp", E, 3);
	//test->setPosition(0, 0);

	//Alien a2("assets/alien.jpg", "Alien");
	//a2.addAnimation("run", &b);
	//a2.setAnimation("run");
	//a2.setPosition(40, 0);

	//Sprite s2("assets/alien.jpg");
	//s2.addAnimation("run", &b);
	//s2.setAnimation("run");
	//s2.setPosition(10, 20);
	//s2.setName("Sprite");

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

	GameState *mainState = new StateMain();
	Image OrionImage("assets/bg.jpg", true);
	Sprite* main_background = Sprite::getInstance(&OrionImage, "Intro background");
	main_background->setPosition(0, 0);
	main_background->toggle_collidable();
	mainState->addGameObject(main_background);

	for (int i = 0; i < 40; i++) {
		mainState->addGameObject(alienArray[i]);
	}
	mainState->addGameObject(ac);
	mainState->addGameObject(player);
	engine->getStateManager()->addGameState("STATE_MAIN", mainState);


	GameState *endState = new StateEnd();
	engine->getStateManager()->addGameState("STATE_END", endState);

	engine->getStateManager()->setCurrentState(introState);

	// run game
	engine->run();

	return (0);
}