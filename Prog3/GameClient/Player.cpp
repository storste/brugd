#include "Player.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/InputHandler.h"
#include <iostream>

Player::Player(const char* filename, const char* name) :Sprite(filename)
{
	setName(name);
}

Player::Player(){
	
}

Player::~Player()
{
}

//const std::string Player::getName()
//{
//	return m_name;
//}
//
//void Player::setName(const char* name)
//{
//	m_name = name;
//}

void Player::update(int dt){

	Sprite::update();

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

	for (const auto& o : GameEngine::getInstance()->getObjects()){

		if (static_cast<GameObject*>(this) != o && GameEngine::getInstance()->cd(this, o)){
			std::cout << "Collision between " << this->getName() << " and " << o->getName() << std::endl;

			GameEngine::getInstance()->removeGameObject(o);
			
		}

		//if (this != o){
		//	std::cout << "Running CD for " << this->getName() << " and " << o->getName() << std::endl;
		//	if (GameEngine::getInstance()->cd(this, o)){
		//		std::cout << "player collided with " << o->getName() << std::endl;
		//	}
		//}

	}
}

