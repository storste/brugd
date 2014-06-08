#pragma once
#include "..\GameEngine\GameEngine.h"
#include "..\GameEngine\AnimatedSprite.h"

enum Direction {
	left,
	right
};

class Alien : public AnimatedSprite {
public:
	static Alien* Alien::getInstance(std::string name);
	~Alien();
	Direction dir;
	void update(int dt);
	void doCollission();
	void updatePosition(int, int);
	void setDir(Direction);
private:
	Uint32 ticks;
protected:
	Alien(std::string name);
};

