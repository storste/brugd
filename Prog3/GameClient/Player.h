#pragma once
#include "..\GameEngine\Sprite.h"

class Player : public Sprite {

public:
	void Update(int dt);
	Player(const char* filename, const char* name);
	Player();
	~Player();

private:
	
};

