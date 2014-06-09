#pragma once
#include "..\..\GameEngine\Sprite.h"
#include "..\..\GameEngine\GameEngine.h"
#include <iostream>

class Bomb :
	public Sprite {
public:
	Bomb(Image* image, std::string name);


	void update(int dt);
	void doCollission();

private:
	Bomb(const Bomb& other);
	const Bomb& operator=(const Bomb& other);
};

