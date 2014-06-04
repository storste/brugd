#include "Alien.h"
#include <iostream>

Alien::Alien(const char* filename, const char* name) : Sprite(filename)

{
	std::cout << "creating alien" << std::endl;
	dir = left;
	setPosition(300, 0);
	setName(name);
}


Alien::~Alien()
{
}

void Alien::update(int dt){

	//std::cout << "moving alien" << std::endl;

	if (dir == left && getX() > 0)
		setPosition(getX() - 1, getY());
	else if (dir == left && getX() == 0)
	{
		setPosition(getX(), getY() + 1);
		dir = right;
	}
	else if (dir == right && getX() < 200)
		setPosition(getX() + 1, getY());
	else if (dir == right && getX() == 200)
	{
		setPosition(getX(), getY() + 1);
		dir = left;
	}

//	std::cout << "Alien @ " << getX() << ":" << getY() << std::endl;


}