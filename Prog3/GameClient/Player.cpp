#include "Player.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/InputHandler.h"
#include <iostream>

Player::Player(const char* filename, SDL_Renderer* r, const char* name) :Sprite(filename, r)
{
	setName(name);
}

Player::Player(){

}


void Player::update(){
	
	Sprite::update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		setPosition(getX() + 1, getY());
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		setPosition(getX() - 1, getY());
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		setPosition(getX(), getY() + 1);
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		setPosition(getX(), getY() - 1);
	}
}

Player::~Player()
{
}
