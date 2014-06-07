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
	MovingObject(const char* filename, MovementDirection dir, int velocity);
	~MovingObject();
	void MovingObject::update();
private:
	int velocity;
	MovementDirection dir;
};

