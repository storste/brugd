#include "Alien.h"
#include <iostream>

Alien::Alien(const char* filename, const char* name) : Sprite(filename)
{
	_name = name;
	dir = right;
	setPosition(0, 0);
}

Alien::Alien(Image* image, const char* name) : Sprite(image,name)
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

	//if (flag == true) {

	//	setPosition(_x, _y + 40);
	//	dir = (dir == left ? right : left);
	//	flag = false;
	//}

	if ((SDL_GetTicks() - ticks) > 500) {
		Sprite::update();

		if (dir == right && getX() < 560)
		{
			setPosition(getX() + 40, getY());
			ticks = SDL_GetTicks();
		}
		else if (dir == right && getX() > 559)
		{
			for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
			{
				if (a->getName() == "Alien"){
					static_cast<Alien*>(a)->setPosition(a->getX(), a->getY() + 40);
					static_cast<Alien*>(a)->dir = left;
				}
			}

			//setPosition(getX() + 40, getY() );
			//dir = left;
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

void Alien::doCollission(){
	std::cout << "Alien: doCollission()" << std::endl;
}