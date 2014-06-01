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

int main(int argc, char *argv[])
{
	GameEngine* engine = GameEngine::getInstance();

	//engine.render_grid_dots();
	//engine.render_dot();


	Animation a("assets/dude.png", engine->getRenderer(), 130, 150, 27, 7);
	Animation b("assets/dude.bmp", engine->getRenderer(), 130, 150, 27, 7);

	Player s1;
	s1.addAnimation("run", &a);
	s1.setAnimation("run");
	s1.setPosition(100, 200);
	s1.setName("player");


	Sprite s2("assets/poteto.bmp");
	//s2.addAnimation("run", &b);
	//s2.setAnimation("run");
	s2.setPosition(10, 20);
	s2.setName("Sprite");

	//Sprite s2("../GameEngine/golddot.png", engine.getRenderer());
	//s2.setPosition(200, 300);

	//Player p1("../../animation/assets/dude.bmp", engine.getRenderer(), "Player 1");
	//Player p2("../GameEngine/golddot.png", engine.getRenderer(), "Player 2");


	//std::cout << p1.getName() << std::endl;

	engine->addDrawable(&s2);
	engine->addDrawable(&s1);


	engine->run();

	//engine.render();
	//std::string tmp;
	//std::cin >> tmp;


	//engine.graph();

	return (0);
}