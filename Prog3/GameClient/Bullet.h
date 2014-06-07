#pragma once
#include "..\GameEngine\MovingObject.h"

class Bullet :
	public MovingObject
{
public:
	Bullet(const char* filename, MovementDirection dir, int velocity);
	~Bullet();
	void update(int dt);
};

