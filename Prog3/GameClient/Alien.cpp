#include "Alien.h"
#include "AlienController.h"
#include <iostream>

Alien::Alien(const char* filename, const char* name) : Sprite(filename)
{
	_name = name;
	dir = right;
	setPosition(0, 0);
}

Alien::Alien(Image* image, const char* name) : Sprite(image, name)
{
	_name = name;
	dir = right;
	setPosition(0, 0);
}


Alien::~Alien()
{

	std::cout << "aLIEN : I AAAAM DESTRUCTOR - WARAWRARARWARWA" << std::endl;
}

void Alien::update(int dt){


	//	if (dir == right && getX() < 600)
	//	{
	//		setPosition(getX() + 40, getY());
	//		ticks = SDL_GetTicks();
	//	}

	if (dir == right && _x > 599)
	{
		for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
		{
			if (a->getName() == "AlienController"){
				static_cast<AlienController*>(a)->setCollideRight();
			}
		}
	}
	else if (dir == left && _x < 1)
	{
		for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
		{
			if (a->getName() == "AlienController"){
				static_cast<AlienController*>(a)->setCollideLeft();
			}
		}
	}

	//		//setPosition(getX() + 40, getY() );
	//		//dir = left;
	//		ticks = SDL_GetTicks();
	//	}
	//	else if (dir == left && getX() > 0)
	//	{
	//		setPosition(getX() - 40, getY());
	//		ticks = SDL_GetTicks();
	//	}
	//	else if (dir == left && getX() < 1)
	//	{
	//		setPosition(getX(), getY() + 40);
	//		dir = right;
	//		ticks = SDL_GetTicks();
	//	}
	//}
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

void Alien::doCollission(){
	std::cout << "Alien: doCollission()" << std::endl;
}

void Alien::updatePosition(int x, int y) {
	setPosition(_x + x, _y + y);
	Sprite::update();
}

void Alien::setDir(Direction d){
	dir = d;
}