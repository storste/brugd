#include "Bomb.h"
#include <iostream>

Bomb::Bomb(Image* image, std::string name) : Sprite(image, name)
{
	m_collidable = true;
}

Bomb::~Bomb(){}

void Bomb::update(int dt){

	setPosition(getX(), _y + 3);
	if (_y > 600 - _h)
		m_visible = false;

	for (auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

		if (static_cast<GameObject*>(this) != o && o->getName() != "Alien" && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){

			//std::cout << "Collission between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

			o->doCollission();
			//GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
			doCollission();
		}
	}
}

void Bomb::doCollission(){
	GameEngine::getInstance()->score++;
	GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(this);
}
