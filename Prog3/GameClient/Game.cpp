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


	Sprite s1("assets/dude.bmp", engine.getRenderer());
	s1.setPosition(0, 0);

	engine.addDrawable(&s1);
	//engine.addDrawable(&p2);


	engine.run();

	return (0);
}