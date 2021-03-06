#ifndef MISSILE_H
#define MISSILE_H

#include "../../GameEngine/Sprite.h"

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

#endif