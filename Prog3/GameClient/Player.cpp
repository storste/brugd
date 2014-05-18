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


void Player::update(int dt){
	Sprite::update(dt);

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{	
		Sprite::getAnimation()->setFlip(false);
		setPosition(getX() + 1, getY());
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		Sprite::getAnimation()->setFlip(true);
		setPosition(getX() - 2, getY());
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		setPosition(getX(), getY() + 3);
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		setPosition(getX(), getY() - 4);
	}
}

Player::~Player()
{
}
