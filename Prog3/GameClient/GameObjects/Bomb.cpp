#include "../../GameEngine/GameEngine.h"
#include <iostream>
#include "Bomb.h"

Bomb::Bomb(Image* image, std::string name) : Sprite(image, name)
{
}



void Bomb::update(int dt){

	setPosition(getX(), getY() + 3);
	if (getY() > GameEngine::getInstance()->getScreenHeight() - getH())
		toggle_visible();

	for (auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){
		if (o){
			//if (static_cast<GameObject*>(this) != o && o->getName() != "Alien" && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
			if (this != o && o->getName() == "Tank" && GameEngine::getInstance()->cd(this, o)){

				//		//std::cout << "Collission between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

				o->doCollission();
				//		//GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
				doCollission();
			}
		}
	}
}

void Bomb::doCollission(){
	GameEngine::getInstance()->addToScore(-10);
	GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(this);
}

