#include "Alien.h"
#include <iostream>

Alien::Alien(const char* filename, const char* name) : Sprite(filename)
{
	_name = name;
	dir = right;
	setPosition(0, 0);
}


Alien::~Alien()
{
}

void Alien::Update(int dt){

	if ((SDL_GetTicks() - ticks) > 500) {
		Sprite::Update();
		std::cout << getX() << std::endl;


		if (dir == right && getX() < 560)
		{
			setPosition(getX() + 40, getY());
			ticks = SDL_GetTicks();
		}
		else if (dir == right && getX() > 559)
		{
			setPosition(getX(), getY() + 40);
			dir = left;
			ticks = SDL_GetTicks();
		}
		else if (dir == left && getX() > 0)
		{
			setPosition(getX() - 40, getY());
			ticks = SDL_GetTicks();
		}
		else if (dir == left && getX() < 1)
		{
			setPosition(getX(), getY() + 40);
			dir = right;
			ticks = SDL_GetTicks();
		}
	}
	//	//std::cout << "moving alien" << std::endl;
	//
	//	if (dir == left && getX() > 0)
	//		setPosition(getX() - 1, getY());
	//	else if (dir == left && getX() == 0)
	//	{
	//		setPosition(getX(), getY() + 1);
	//		dir = right;
	//	}
	//	else if (dir == right && getX() < 200)
	//		setPosition(getX() + 1, getY());
	//	else if (dir == right && getX() == 200)
	//	{
	//		setPosition(getX(), getY() + 1);
	//		dir = left;
	//	}
	//
	//	std::cout << "Alien @ " << getX() << ":" << getY() << std::endl;


}