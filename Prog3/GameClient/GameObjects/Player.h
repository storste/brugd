#ifndef PLAYER_H
#define PLAYER_H

#include "../../GameEngine/AnimatedSprite.h"

class Player : public AnimatedSprite {

public:
	static Player* getInstance();

	void update(int dt);
	void doCollission();

	void shoot();
	void moveRight();
	void moveLeft();

private:
	int timeSinceLastShot;
	bool animationFlip = false;
	int w;
	int h;
	Player();
	Player(const Player& other);
	const Player& operator=(const Player& other);
};

#endif