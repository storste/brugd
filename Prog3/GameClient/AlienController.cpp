#include "AlienController.h"
#include "Alien.h"
#include "..\GameEngine\GameEngine.h"


AlienController::AlienController() : ticks(SDL_GetTicks()), collideRight(false), collideLeft(false), dir(right)
{
	_name = "AlienController";
}


AlienController::~AlienController()
{
}

void AlienController::setCollideRight() {
	collideRight = true;
}

void AlienController::setCollideLeft() {
	collideLeft = true;
}


void AlienController::update(int dt) {

	if ((SDL_GetTicks() - ticks) > 500) {

		if (collideRight) {
			for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
			{
				if (a->getName() == "Alien"){
					static_cast<Alien*>(a)->updatePosition(0, 40);
					static_cast<Alien*>(a)->setDir(left);
				}
			}
			collideRight = false;
			dir = left;
		}
		else if (collideLeft)
		{
			for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
			{
				if (a->getName() == "Alien"){
					static_cast<Alien*>(a)->updatePosition(0, 40);
					static_cast<Alien*>(a)->setDir(right);
				}
			}
			collideLeft = false;
			dir = right;
		}
		else if (dir == right)
		{
			for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
			{
				if (a->getName() == "Alien"){
					static_cast<Alien*>(a)->updatePosition(40, 0);
				}
			}
		}

		else if (dir == left)
		{
			for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
			{
				if (a->getName() == "Alien"){
					static_cast<Alien*>(a)->updatePosition(-40, 0);
				}
			}

		}

		ticks = SDL_GetTicks();
	}

}