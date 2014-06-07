#pragma once
#include "..\GameEngine\Sprite.h"
#include "..\GameEngine\GameEngine.h"
#include "Missile.h"

class Player : public Sprite {

public:
	void Update(int dt);
	Player(const char* filename, const char* name);
	Player();
	~Player();

	void Shoot(){

		printf("Shooting missile from position %d:%d\n", _x, _y);

		Sprite* missile = new Missile("assets/missile.png", "Missile");
		missile->setPosition(_x, _y - 20);
		missile->toggle_collidable();
		GameEngine::getInstance()->getStateManager()->getCurrentState()->addGameObject(missile);
	}

private:
	
};

