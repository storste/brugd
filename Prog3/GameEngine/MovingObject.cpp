#include "MovingObject.h"


MovingObject::MovingObject(const char* filename, MovementDirection d, int v) : Sprite(filename), dir(d), velocity(v)
{
}


MovingObject::~MovingObject()
{
}

void MovingObject::update() {
	switch (dir)
	{
	case N:
		setPosition(getX(), getY() - velocity);
		Sprite::update();
		break;
	case S:
		setPosition(getX(), getY() + velocity);
		Sprite::update();
		break;
	case E:
		setPosition(getX() + velocity, getY());
		Sprite::update();
		break;
	case W:
		setPosition(getX() - velocity, getY());
		Sprite::update();
		break;
	default: 
		break;
	}
}