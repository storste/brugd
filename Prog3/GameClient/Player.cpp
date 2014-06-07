#include <iostream>
#include "Player.h"
#include "../GameEngine/GameEngine.h"


Player::Player(const char* filename, const char* name) :Sprite(filename)
{
	_name = name;
}

Player::Player(){}

Player::~Player(){
	std::cout << "Player: Destructor" << std::endl;
}

void Player::update(int dt){

	Sprite::update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		Shoot();
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		Sprite::setAnimation("run");
		Sprite::getAnimation()->setFlip(false);
		setPosition(getX() + 1, getY());
		Sprite::update();
	}

	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		Sprite::setAnimation("run");
		Sprite::getAnimation()->setFlip(true);
		setPosition(getX() - 1, getY());
		Sprite::update();
	}

	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		setPosition(getX(), getY() + 1);
	}

	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		setPosition(getX(), getY() - 1);
	}

	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		//GameEngine::getInstance()->quit();
	}

	else {
		//Sprite::setAnimation("idle");
		//Sprite::update();
	}

	for (const auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

		if (static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
			std::cout << "Collision between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

			GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);

		}
	}
}

