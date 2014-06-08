#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "..\..\GameEngine\GameEngine.h"
#include "..\..\GameEngine\AnimatedSprite.h"

#include "Missile.h"
#include "Bomb.h"

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
	bool Alien::clearBelow();
	void Shoot();
	Alien(const Alien& other);
	const Alien& operator=(const Alien& other);
protected:
	Alien(std::string name);
};

