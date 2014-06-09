#pragma once
#include "..\..\GameEngine\Sprite.h"
#include "..\..\GameEngine\GameEngine.h"
#include <iostream>

class Missile :
	public Sprite {
public:
	Missile(Image* image, std::string name);

	void update(int dt);
	void doCollission();

private:
	Missile(const Missile& other);
	const Missile& operator=(const Missile& other);
};

