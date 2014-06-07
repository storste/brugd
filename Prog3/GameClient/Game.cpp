#include "..\GameEngine\GameEngine.h"

#include "Player.h"
#include "Alien.h"
#include "Missile.h"
#include "Bullet.h"
//#include "..\GameEngine\InputHandler.h"

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
	Animation b("assets/dude.bmp", 130, 150, 27, 7, 0);

	Sprite* player = new Player();
	player->addAnimation("run", &a);
	player->setAnimation("run");
	player->setPosition(100, 200);
	player->setName("Player");

	//Alien* alienArray[5];

	//for (int i = 0; i < 5; i++) {
	//	alienArray[i] = new Alien("assets/alien.jpg", "Alien");
	//	alienArray[i]->addAnimation("run", &b);
	//	alienArray[i]->setAnimation("run");
	//	alienArray[i]->setPosition((i * 80), 0);
	//}
	
	Sprite* alien = new Alien ("assets/alien.jpg", "Alien");
	alien->addAnimation("run", &b);
	alien->setAnimation("run");

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
	Sprite intro_background("assets/intro.png", "Intro background");
	intro_background.setPosition(0, 0);
	introState->addGameObject(&intro_background);
	engine->getStateManager()->addGameState(STATE_INTRO, introState);

	GameState *pauseState = new StatePause();
	Sprite pause_background("assets/pause.png", "Pause background");
	pause_background.setPosition(0, 0);
	pauseState->addGameObject(&pause_background);
	engine->getStateManager()->addGameState(STATE_PAUSE, pauseState);

	GameState *mainState = new StateMain();
	Sprite main_background("assets/main.png", "Main background");
	main_background.setPosition(0, 0);
	main_background.toggle_collidable();
	mainState->addGameObject(&main_background);
	mainState->addGameObject(alien);
	mainState->addGameObject(player);
	engine->getStateManager()->addGameState(STATE_MAIN, mainState);

	GameState *endState = new StateEnd();
	engine->getStateManager()->addGameState(STATE_END, endState);

	engine->getStateManager()->setCurrentState(introState);
	//engine->getStateManager()->stateID = STATE_INTRO;

	//engine->addDrawable(&s2);
	//engine->addDrawable(&player);

	//for (int i = 0; i < 5; i++) {
	//	engine->addDrawable(alienArray[i]);
	//}


	// run game
	engine->run();


	return (0);
}