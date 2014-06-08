#include "Alien.h"
#include "AlienController.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../GameEngine/GameEngine.h"


Alien* Alien::getInstance(std::string name){
	return new Alien(name);
}

Alien::Alien(std::string name) : AnimatedSprite(name)
{
	dir = right;
	setPosition(0, 0);
}

Alien::~Alien()
{
	for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
	{
		if (a->getName() == "AlienController"){
			static_cast<AlienController*>(a)->decreaseUpdateSpeed(15);
}
	}
}

void Alien::update(int dt){

	int random = rand() % 400 + 1;

		if (random == 1 && clearBelow()){
			Shoot();
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
	else if (dir == left && _x < 10)
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
	setPosition(getX()-30,getY()-33);
	std::cout << "Alien: doCollission()" << std::endl;
}

void Alien::updatePosition(int x, int y) {
	setPosition(_x + x, _y + y);
	AnimatedSprite::update();
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


	Image bombImage("assets/redLaserRay.png", true);
	Sprite* missile = new Bomb(&bombImage, "a");

	missile->setPosition(_x + (_w / 2) - 4, _y + 30);



	missile->toggle_collidable();
	GameEngine::getInstance()->getStateManager()->getCurrentState()->addGameObject(missile);
}
