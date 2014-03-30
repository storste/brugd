#include "Player.h"


Player::Player(const char* filename, SDL_Renderer* r, const char* name) :Sprite(filename, r)
{
	setName(name);
}


Player::~Player()
{
}
