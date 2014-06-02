#pragma once
#include "..\GameEngine\Sprite.h"

class Player : public Sprite {

public:
	void Player::update(int dt);
	Player(const char* filename, const char* name);
	Player();
	~Player();
	const std::string getName();
	void setName(const char* name);

private:
	std::string m_name;
};

