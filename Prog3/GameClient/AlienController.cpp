#include "AlienController.h"
#include "Alien.h"
#include "..\GameEngine\GameEngine.h"


AlienController::AlienController() : ticks(SDL_GetTicks()), collideRight(false), collideLeft(false), dir(right), updateSpeed(1000)
{
	m_name = "AlienController";
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


void AlienController::updateAliens(int x, int y)
{
	for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
	{
		if (a->getName() == "Alien"){
			static_cast<Alien*>(a)->updatePosition(x, y);
		}
	}
}

void AlienController::updateAliens(int x, int y, Direction d)
{
	for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
	{
		if (a->getName() == "Alien"){
			static_cast<Alien*>(a)->updatePosition(x, y);
			static_cast<Alien*>(a)->setDir(d);
		}
	}
}

void AlienController::decreaseUpdateSpeed(int i){
	updateSpeed -= i;
}

void AlienController::update(int dt) {

	if ((SDL_GetTicks() - ticks) > updateSpeed) {

		if (collideRight) {
			updateAliens(0, 40, left);
			collideRight = false;
			dir = left;
		}
		else if (collideLeft)
		{
			updateAliens(0, 40, right);
			collideLeft = false;
			dir = right;
		}
		else if (dir == right)
		{
			updateAliens(40, 0);
		}

		else if (dir == left)
		{
			updateAliens(-40, 0);
		}

		ticks = SDL_GetTicks();
	}

}