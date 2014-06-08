#include "Alien.h"
#include "AlienController.h"
#include <iostream>

Alien::Alien(Image* image, std::string name) : Sprite(image, name), ticks(SDL_GetTicks())
{
	dir = right;
	setPosition(0, 0);
}

Alien::~Alien()
{
	for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
	{
		if (a->getName() == "AlienController"){
			static_cast<AlienController*>(a)->decreaseUpdateSpeed(20);
		}
	}
	std::cout << "alien död" << std::endl;
}

void Alien::update(int dt){

	if (SDL_GetTicks() - ticks > 2000) {
		if (clearBelow()){
			Shoot();
			ticks = SDL_GetTicks();
		}
	}

	if (dir == right && _x > GameEngine::getInstance()->getWidth() - 41)
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
}

void Alien::doCollission(){
	setAnimation("explosion");
	//std::cout << "Alien: doCollission()" << std::endl;
}

void Alien::updatePosition(int x, int y) {
	setPosition(_x + x, _y + y);
	Sprite::update();
}

void Alien::setDir(Direction d){
	dir = d;
}

bool Alien::clearBelow(){

	bool clear = true;

	for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
	{
		if (a->getName() == "Alien"){
			if (static_cast<Alien*>(a)->getY() > _y) {
				if (static_cast<Alien*>(a)->getX() == _x) {
					clear = false;
				}
			}
		}
	}
	return clear;
}

void Alien::Shoot(){


	Image missileImage("assets/bullet.png", true);
	Sprite* missile = new Bomb(&missileImage, "a");

	missile->setPosition(_x + (_w / 2) - 4, _y + 30);



	missile->toggle_collidable();
	GameEngine::getInstance()->getStateManager()->getCurrentState()->addGameObject(missile);
}
