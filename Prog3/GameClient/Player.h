#pragma once
#include "..\GameEngine\Sprite.h"

class Player :
	public Sprite {
public:
	void Player::update();
	Player(const char* filename, SDL_Renderer* r, const char* name);
	Player();
	~Player();
	std::string getName(){ return m_name; }
private:
	std::string m_name;
};

