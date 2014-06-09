#pragma once
#include "Alien.h"
#include "AlienController.h"

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
	//for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
	//{
	//	if (a->getName() == "AlienController"){
	//		dynamic_cast<AlienController*>(a)->decreaseUpdateSpeed(15);
	//	}
	//}
}

void Alien::update(int dt){

	if (SDL_GetTicks() % 9 == 0)
		AnimatedSprite::update();

	int random = rand() % 400 + 1;

	if (random == 1 && clearBelow()){
		dropBomb();
	}

	if (dir == right && getX() > GameEngine::getInstance()->getScreenWidth() - 41)
	{
		for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
		{
			if (a->getName() == "AlienController"){
				static_cast<AlienController*>(a)->setCollideRight();
			}
		}
	}
	else if (dir == left && getX() < 10)
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
	setPosition(getX() - 30, getY() - 33);
}

void Alien::setDir(Direction d){
	dir = d;
}

bool Alien::clearBelow(){

	bool clear = true;

	for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
	{
		if (a->getName() == "Alien"){
			if (static_cast<Alien*>(a)->getY() > getY()) {
				if (static_cast<Alien*>(a)->getX() == getX()) {
					clear = false;
				}
			}
		}
	}
	return clear;
}

void Alien::dropBomb(){

	Image bombImage("assets/redLaserRay.png", true);
	Sprite* bomb = new Bomb(&bombImage, "Bomb");

	bomb->setPosition(getX() + (getW() / 2) - 4, getY() + 30);
	bomb->toggle_collidable();
	GameEngine::getInstance()->getStateManager()->getCurrentState()->addGameObject(bomb);
}
