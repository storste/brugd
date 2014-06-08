#pragma once
#include <iostream>
#include "..\..\GameEngine\AnimatedSprite.h"
#include "..\..\GameEngine\GameEngine.h"
#include "Missile.h"


class Player : public AnimatedSprite {

public:
	static Player* Player::getInstance();

	void update(int dt);
	void doCollission();

	~Player();

	void shoot();
	void moveRight();
	void moveLeft();

private:
	int timeSinceLastShot;
	bool animationFlip;
	int w;
	int h;
	Player();
	Player(const Player& other);
	const Player& operator=(const Player& other);
};

