#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "..\GameEngine\GameEngine.h"

//#include "..\GameEngine\Animation.h"
//#include "..\GameEngine\Sprite.h"

#include "Player.h"
#include "Alien.h"
#include "Bullet.h"
//#include "..\GameEngine\InputHandler.h"

// forward declare Animation
class Animation;

// forward declare Image
class Image;

int main(int argc, char *argv[])
{
	GameEngine* engine = GameEngine::getInstance();

	Animation a("assets/usagitsukino.png", 32, 48, 4, 4, 96);
	Animation aa("assets/usagitsukino.png", 32, 48, 1, 1, 144);
	Animation b("assets/alien.jpg", 40, 38, 2, 2, 0);

	Player s1;
	s1.addAnimation("run", &a);
	s1.addAnimation("idle", &aa);
	s1.setAnimation("idle");
	s1.setPosition(0, 430);
	s1.setName("Player");

	Alien* alienArray [5];

	for (int i = 0; i < 5; i++) {
		alienArray[i] = new Alien("assets/alien.jpg", "Alien");
		alienArray[i]->addAnimation("run", &b);
		alienArray[i]->setAnimation("run");
		alienArray[i]->setPosition((i * 80), 0);
	}
	
	//Alien a1("assets/alien.jpg", "Alien");
	//a1.addAnimation("run", &b);
	//a1.setAnimation("run");

	//Alien a2("assets/alien.jpg", "Alien");
	//a2.addAnimation("run", &b);
	//a2.setAnimation("run");
	//a2.setPosition(40, 0);

	//Sprite s2("assets/alien.jpg");
	//s2.addAnimation("run", &b);
	//s2.setAnimation("run");
	//s2.setPosition(10, 20);
	//s2.setName("Sprite");

	//std::cout << s1.getName() << std::endl;

	//engine->addDrawable(&s2);
	engine->addGameObject(&s1);

	for (int i = 0; i < 5; i++) {
		engine->addGameObject(alienArray[i]);
	}

	engine->run();


	return (0);
}