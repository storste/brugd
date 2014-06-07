#pragma once
#include "..\GameEngine\GameEngine.h"
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
	void setFlag(bool b) { flag = b; }
private:
	Uint32 ticks;
	bool flag = false;
};

