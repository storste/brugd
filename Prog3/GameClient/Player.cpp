#include <iostream>
#include "Player.h"
#include "../GameEngine/GameEngine.h"


Player::Player(const char* filename, const char* name) :Sprite(filename), timeSinceLastShot(SDL_GetTicks())
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
		if (SDL_GetTicks() - timeSinceLastShot > 1000)
		{
		Shoot();
			timeSinceLastShot = SDL_GetTicks();
	}
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		Sprite::setAnimation("run");
		Sprite::getAnimation()->setFlip(false);
		setPosition(getX() + 1, getY());
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		Sprite::setAnimation("run");
		Sprite::getAnimation()->setFlip(true);
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

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		//GameEngine::getInstance()->quit();
	}

	//if (!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	//{
	//	keyPressed = false;
	//}


	//else {
	//	Sprite::setAnimation("idle");
	//	Sprite::update();
	//}

	for (const auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

		if (static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
			std::cout << "Collision between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

			GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
			
		}
	}
}

void Player::Shoot(){

	printf("Shooting missile from position %d:%d\n", _x, _y);
	//Image missileImage("assets/missile.png", true);
	Sprite* missile = new Missile("assets/missile.png", "a");
	missile->setPosition(_x, _y - 20);
	missile->toggle_collidable();
	GameEngine::getInstance()->getStateManager()->getCurrentState()->addGameObject(missile);
}