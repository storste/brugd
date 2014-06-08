#pragma once
#include "..\GameEngine\Sprite.h"
#include "..\GameEngine\GameEngine.h"
#include "Missile.h"

class Player : public Sprite {

public:
	void update(int dt);
	Player(std::string filename, std::string name);
	Player();
	~Player();

	void shoot();
	void moveRight();
	void moveLeft();

private:
	int timeSinceLastShot;
	bool animationFlip;
	int w;
	int h;
};

