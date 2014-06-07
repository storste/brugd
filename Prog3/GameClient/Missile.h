#pragma once
#include "..\GameEngine\Sprite.h"
#include "..\GameEngine\GameEngine.h"
#include <iostream>

class Missile :
	public Sprite {
public:
	Missile(const char* filename, const char* name);
	Missile(Image* image, const char* name);
	~Missile();

	void update(int dt);

		//std::cout << "Missile: update" << std::endl;
		setPosition(getX(), _y - 7);
		if (_y < 0 - _h)
			_visible = false;

		for (auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

			if (static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
				std::cout << "Collission between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

				GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
				DoCollission();
			}
		}
	}

	void DoCollission(){
		GameEngine::getInstance()->score++;
		GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(this);
	}
};

