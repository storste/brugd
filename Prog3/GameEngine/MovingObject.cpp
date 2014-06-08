#include "MovingObject.h"
#include <iostream>

//MovingObject::MovingObject(std::string filename, MovementDirection d, int v) : Sprite(filename), dir(d), velocity(v)
//{
//}


MovingObject::~MovingObject()
{
}

void MovingObject::update(int dt) {
	std::cout << getX() << std::endl;
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