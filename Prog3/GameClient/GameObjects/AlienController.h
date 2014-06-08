#pragma once
#include "Alien.h"
#include "..\..\GameEngine\GameEngine.h"

class AlienController :
	public GameObject
{
public:
	AlienController();
	~AlienController();
	void update(int dt);
	void render(){}
	void doCollission(){}
	void setCollideRight();
	void setCollideLeft(); 
	void decreaseUpdateSpeed(int);
private:
	Uint32 ticks;
	bool collideRight;
	bool collideLeft;
	Direction dir;
	void updateAliens(int x, int y, Direction d);
	void updateAliens(int x, int y);
	Uint32 updateSpeed;
	AlienController(const AlienController& other);
	const AlienController& operator=(const AlienController& other);
};

