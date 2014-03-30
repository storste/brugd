#pragma once
#include "..\GameEngine\Sprite.h"

class Player :
	public Sprite {
public:
	Player(const char* filename, SDL_Renderer* r, const char* name);
	~Player();
};

