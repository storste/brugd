#pragma once
#include "..\GameEngine\GameEngine.h"
#include "..\GameEngine\Sprite.h"

enum Direction {
	left,
	right
};

class Alien :
	public Sprite {
public:
	Alien(Image* image, std::string name);
	~Alien();
	Direction dir;
	void update(int dt);
	void doCollission();

private:
	Uint32 ticks;
};

