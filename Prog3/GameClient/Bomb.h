#pragma once
#include "..\GameEngine\Sprite.h"
#include "..\GameEngine\GameEngine.h"
#include <iostream>

class Bomb :
	public Sprite {
public:
	Bomb(Image* image, std::string name);
	~Bomb();

	void update(int dt);
	void doCollission();

};

