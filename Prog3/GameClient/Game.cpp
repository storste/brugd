#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "..\GameEngine\GameEngine.h"

#include "Player.h"
#include "Alien.h"

#include "StateMain.h"
#include "StateIntro.h"
#include "StatePause.h"

// forward declare Animation
class Animation;

// forward declare Image
class Image;




int main(int argc, char *argv[])
{
	GameEngine* engine = GameEngine::getInstance();

	Animation a("assets/dude.png", 130, 150, 27, 7);
	Animation b("assets/dude.bmp", 130, 150, 27, 7);

	Player player;
	player.addAnimation("run", &a);
	player.setAnimation("run");
	player.setPosition(100, 200);
	player.setName("Player");

	Alien* alienArray[5];

	for (int i = 0; i < 5; i++) {
		alienArray[i] = new Alien("assets/alien.jpg", "Alien");
		alienArray[i]->addAnimation("run", &b);
		alienArray[i]->setAnimation("run");
		alienArray[i]->setPosition((i * 80), 0);
	}

	Alien a1("assets/alien.jpg", "Alien");
	a1.addAnimation("run", &b);
	a1.setAnimation("run");

	//Alien a2("assets/alien.jpg", "Alien");
	//a2.addAnimation("run", &b);
	//a2.setAnimation("run");
	//a2.setPosition(40, 0);

	Sprite s2("assets/alien.jpg");
	s2.addAnimation("run", &b);
	s2.setAnimation("run");
	s2.setPosition(10, 20);
	s2.setName("Sprite");

	//std::cout << player.getName() << std::endl;


	// set up game states
	GameState *introState = new StateIntro();
	Sprite intro_background("assets/intro.png");
	intro_background.setPosition(0, 0);
	introState->addGameObject(&intro_background);
	engine->getStateManager()->addGameState(STATE_INTRO, introState);

	GameState *pauseState = new StatePause();
	Sprite pause_background("assets/pause.png");
	pause_background.setPosition(0, 0);
	pauseState->addGameObject(&pause_background);
	engine->getStateManager()->addGameState(STATE_PAUSE, pauseState);

	GameState *mainState = new StateMain();
	Sprite main_background("assets/main.png", "Main background");
	main_background.setPosition(0, 0);
	main_background.toggle_collidable();
	mainState->addGameObject(&s2);
	mainState->addGameObject(&main_background);
	mainState->addGameObject(&a1);
	mainState->addGameObject(&player);
	engine->getStateManager()->addGameState(STATE_MAIN, mainState);

	engine->getStateManager()->setCurrentState(introState);
	engine->getStateManager()->stateID = STATE_INTRO;

	//engine->addDrawable(&s2);
	//engine->addDrawable(&player);

	//for (int i = 0; i < 5; i++) {
	//	engine->addDrawable(alienArray[i]);
	//}


	// run game
	engine->run();


	return (0);
}