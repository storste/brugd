#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <array>
#include "..\GameEngine\GameEngine.h"
//#include "..\GameEngine\Sprite.h"
#include "Player.h"



int main(int argc, char *argv[])
{


	//GameEngine engine = GameEngine::getEngineInstance();

	GameEngine engine = GameEngine();

	//engine.render_grid_dots();
	//engine.render_dot();

	Sprite s1("../GameEngine/golddot.png", engine.getRenderer());
	s1.setPosition(100, 200);

	Sprite s2("../GameEngine/golddot.png", engine.getRenderer());
	s2.setPosition(200, 300);

	Player p1("../GameEngine/golddot.png", engine.getRenderer(), "Player 1");
	Player p2("../GameEngine/golddot.png", engine.getRenderer(), "Player 2");


	std::cout << p1.getName() << std::endl;

	engine.addDrawable(&p1);
	engine.addDrawable(&p2);


	engine.run();

	//engine.render();
	//std::string tmp;
	//std::cin >> tmp;


	//engine.graph();

	return (0);
}