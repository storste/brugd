#pragma once
#include "..\GameEngine\Sprite.h"
#include "..\GameEngine\GameEngine.h"
#include "Missile.h"

class Player : public Sprite {

public:
	void update(int dt);
	Player(const char* filename, const char* name);
	Player();
	~Player();
	void Shoot();

private:
	int timeSinceLastShot;
	bool animationFlip;
	int w;
	int h;
};

