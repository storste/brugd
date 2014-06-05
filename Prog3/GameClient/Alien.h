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
	Alien(const char* filename, const char* name) ;
	~Alien();
	Direction dir;
	void update(int dt);
private:
	Uint32 ticks;
};
