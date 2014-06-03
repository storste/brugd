#pragma once
#include "..\GameEngine\Sprite.h"
enum Direction
{
	left,
	right
};
class Alien :
	public Sprite
{
public:
	Alien();
	~Alien();
	Direction dir;
	void update();
	
};

