#include "Missile.h"
#include <iostream>

Missile::Missile(const char* filename, const char* name) :Sprite(filename)
{
	printf("Creating missile\n");
}

Missile::~Missile()
{
	std::cout << "Missile: Destructor" << std::endl;
}

void Missile::update(int dt){

	//std::cout << "Missile: update" << std::endl;
	setPosition(getX(), _y - 2);
	if (_y == 0 - _h)
		_visible = false;

	for (auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

		if (static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
			std::cout << "Collission between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

			
			o->doCollission();
			GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
			DoCollission();
		}
	}
}

void Missile::DoCollission(){
	GameEngine::getInstance()->score++;
	GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(this);
}
