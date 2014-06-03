#include "Alien.h"


Alien::Alien()
{
	dir = left;
}


Alien::~Alien()
{
}

void Alien::update(){

	if (dir == left && getX() > 0)
		setPosition(getX() - 1, getY());
	else if (dir == left && getX() == 0)
	{
		setPosition(getX(), getY() - 1);
		dir = right;
	}
	else if (dir == right && getX() < 200)
		setPosition(getX() + 1, getY());
	else if (dir == right && getX() == 200)
	{
		setPosition(getX(), getY() - 1);
		dir = right;
	}


}