#ifndef BOMB_H
#define BOMB_H

#include "../../GameEngine/Sprite.h"

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

#endif