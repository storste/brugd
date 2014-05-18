#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "..\GameEngine\GameEngine.h"
#include "..\GameEngine\Animation.h"
//#include "..\GameEngine\Sprite.h"
#include "Player.h"
#include "..\GameEngine\InputHandler.h"


int main(int argc, char *argv[])
{

	GameEngine* engine = GameEngine::getEngineInstance();

	//engine.render_grid_dots();
	//engine.render_dot();


	Animation a("assets/dude.bmp", engine->getRenderer(), 130, 150, 27, 7);
	Animation stand("assets/dude.bmp", engine->getRenderer(), 130, 150, 1, 7);
	Animation b("assets/runningSprite.bmp", engine->getRenderer(), 85, 102, 30, 6);

	Player s1;
	s1.addAnimation("run", &a);
	s1.addAnimation("stand", &stand);
	s1.setAnimation("run");
	s1.setPosition(100, 200);

	Sprite s2;
	s2.addAnimation("run", &b);
	s2.setAnimation("run");
	s2.setPosition(0, 0);

	//Sprite s2("../GameEngine/golddot.png", engine.getRenderer());
	//s2.setPosition(200, 300);

	//Player p1("../../animation/assets/dude.bmp", engine.getRenderer(), "Player 1");
	//Player p2("../GameEngine/golddot.png", engine.getRenderer(), "Player 2");


	//std::cout << p1.getName() << std::endl;

	engine->addDrawable(&s1);
	engine->addDrawable(&s2);


	engine->run();

	//engine.render();
	//std::string tmp;
	//std::cin >> tmp;


	//engine.graph();

	return (0);
}