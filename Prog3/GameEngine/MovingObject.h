#pragma once
#include "Sprite.h"
enum MovementDirection
{
	N,NE,E,SE,S,SW,W,NW
};

class MovingObject :
	public Sprite
{
public:
	MovingObject(std::string filename, MovementDirection dir, int velocity);
	~MovingObject();
	void MovingObject::update(int dt);
private:
	int velocity;
	MovementDirection dir;
};

