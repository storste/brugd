#pragma once
#include "..\GameEngine\Sprite.h"
#include "..\GameEngine\GameEngine.h"
#include <iostream>

class Missile :
	public Sprite {
public:
	Missile(const char* filename, const char* name);
	Missile(Image* image, const char* name);
	~Missile();

	void update(int dt);

	void DoCollission();
};

