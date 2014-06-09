#include "AlienController.h"

AlienController::AlienController() : ticks(SDL_GetTicks()), collideRight(false), collideLeft(false), dir(right), updateSpeed(1000)
{
	setName("AlienController");
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
			a->setPosition(a->getX() + x, a->getY() + y);
		}
	}
}

void AlienController::updateAliens(int x, int y, Direction d)
{
	for (auto& a : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects())
	{
		if (a->getName() == "Alien"){
			a->setPosition(a->getX() + x, a->getY() + y);
			dynamic_cast<Alien*>(a)->setDir(d);
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