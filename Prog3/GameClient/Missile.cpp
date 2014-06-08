#include "Missile.h"
#include <iostream>

Missile::Missile(Image* image, std::string name) : Sprite(image, name)
{
	printf("Creating missile\n");
}

Missile::~Missile()
{
	std::cout << "Missile: Destructor" << std::endl;
}

void Missile::update(int dt){

	//std::cout << "Missile: update" << std::endl;
	setPosition(getX(), _y - 7);
	if (_y == 0 - _h)
		m_visible = false;

	for (auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

		if (static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
	
			std::cout << "Collission between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

			o->doCollission();
			GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
			doCollission();
		}
	}
}

void Missile::doCollission(){
	GameEngine::getInstance()->score++;
	GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(this);
}
