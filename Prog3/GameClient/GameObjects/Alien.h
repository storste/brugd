#ifndef ALIEN_H
#define ALIEN_H

#include "../../GameEngine/AnimatedSprite.h"

enum Direction {
	left = -40,
	right = 40,
	no_change = 0
};

class Alien : public AnimatedSprite {
public:
	static Alien* getInstance(std::string name);
	~Alien();
	void update(int dt);
	void doCollission();
	void setDir(Direction);

private:
	Uint32 ticks;
	Direction dir;
	bool clearBelow();
	void dropBomb();
	Alien(const Alien& other);
	const Alien& operator=(const Alien& other);
protected:
	Alien(std::string name);
};

#endif