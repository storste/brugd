#pragma once
#include <list>
#include "Alien.h"
#include "..\GameEngine\GameEngine.h"

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
private:
	int ticks;
	bool collideRight;
	bool collideLeft;
	Direction dir;
};

