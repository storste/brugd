#include "Missile.h"

Missile::Missile(Image* image, std::string name) : Sprite(image, name)
{
}

Missile::~Missile(){}

void Missile::update(int dt){

	setPosition(getX(), getY() - 7);
	if (getY() < 0 - getH())
		toggle_visible();

	for (auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

		if (o->getName() != "Tank" && static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
	
			////std::cout << "Collission between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

			o->doCollission();
			GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
			doCollission();
		}
	}
}

void Missile::doCollission(){
	GameEngine::getInstance()->score++;
	std::cout << "Increasing score: " << GameEngine::getInstance()->score << std::endl;
	GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(this);
}
