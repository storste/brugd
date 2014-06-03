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
//#include "..\GameEngine\InputHandler.h"

// forward declare Animation
class Animation;

// forward declare Image
class Image;

int main(int argc, char *argv[])
{
	GameEngine* engine = GameEngine::getInstance();

	Animation a("assets/dude.png", engine->getRenderer(), 130, 150, 27, 7);
	Animation b("assets/dude.bmp", engine->getRenderer(), 130, 150, 27, 7);

	Player s1;
	s1.addAnimation("run", &a);
	s1.setAnimation("run");
	s1.setPosition(100, 200);
	s1.setName("Player");


	Sprite s2("assets/poteto.bmp");
	//s2.addAnimation("run", &b);
	//s2.setAnimation("run");
	s2.setPosition(10, 20);
	s2.setName("Sprite");

	//std::cout << s1.getName() << std::endl;

	engine->addDrawable(&s2);
	engine->addDrawable(&s1);


	std::cout << "w: " << s1.getW() << " h: " << s1.getH() << std::endl;


	engine->run();


	return (0);
}