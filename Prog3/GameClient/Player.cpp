#include <iostream>
#include "Player.h"
#include "../GameEngine/GameEngine.h"


Player::Player(const char* filename, const char* name) :Sprite(filename), timeSinceLastShot(SDL_GetTicks()), w(640), h(480)
{
	_name = name;
}

Player::Player() : timeSinceLastShot(SDL_GetTicks()), w(640), h(480) {}

Player::~Player(){
	std::cout << "Player: Destructor" << std::endl;
}

void Player::update(int dt){

	Sprite::update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		if (SDL_GetTicks() - timeSinceLastShot > 500)
		{
		Shoot();
			timeSinceLastShot = SDL_GetTicks();
	}

	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		Sprite::setAnimation("run");
		animationFlip = true;
		Sprite::getAnimation()->setFlip(animationFlip);
		if (!(_x > w - 65))
			setPosition(getX() + 2, getY());
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		Sprite::setAnimation("run");
		animationFlip = false;
		Sprite::getAnimation()->setFlip(animationFlip);
		if (!(_x < 1))
			setPosition(getX() - 2, getY());

	}

	if (!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		Sprite::setAnimation("idle");
		Sprite::getAnimation()->setFlip(animationFlip);
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

	Sprite* missile = new Missile("assets/bullet.png", "a");
	missile->setPosition(_x + (_w / 2) - 4, _y - 15);
	//Image missileImage("assets/missile.png", true);
	missile->toggle_collidable();
	GameEngine::getInstance()->getStateManager()->getCurrentState()->addGameObject(missile);
}

