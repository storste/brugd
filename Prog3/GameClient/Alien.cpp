#include "Alien.h"


Alien::Alien()
{
	dir = left;
}


Alien::~Alien()
{
}

void Alien::update(){

	if (getX() > 0)
		setPosition(getX() - 1, getY());
	else {
		setPosition(getX(), getY() - 1);
	}


}