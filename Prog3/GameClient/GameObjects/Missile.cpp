#include "Missile.h"

Missile::Missile(Image* image, std::string name) : Sprite(image, name)
{
}

void Missile::update(int dt){

	setPosition(getX(), getY() - 7);
	if (getY() < 0 - getH())
		toggle_visible();

	for (auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){
		if (o){
			if (o->getName() != "Tank" && static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
				o->doCollission();
				GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
				doCollission();
				break;
			}
		}
	}
}

void Missile::doCollission(){
	GameEngine::getInstance()->addToScore(1);
	GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(this);
}
