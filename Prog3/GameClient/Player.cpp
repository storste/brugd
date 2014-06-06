#include <iostream>
#include "Player.h"
#include "../GameEngine/GameEngine.h"


Player::Player(const char* filename, const char* name) :Sprite(filename)
{
	setName(name);
}

Player::Player(){
	
}

Player::~Player()
{
}

void Player::Update(int dt){

	Sprite::Update();

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

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		GameEngine::getInstance()->quit();
	}

	for (const auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

		if (static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
			std::cout << "Collision between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

			GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
			
		}
	}
}

