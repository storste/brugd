#include <iostream>
#include "Player.h"
#include "../GameEngine/GameEngine.h"

//Player::Player(std::string filename, std::string name) :Sprite(filename, name), timeSinceLastShot(SDL_GetTicks()), w(640), h(480)
//{
//}

Player::Player() : timeSinceLastShot(SDL_GetTicks()), w(640), h(480) {}

Player::~Player(){
	std::cout << "Player: Destructor" << std::endl;
}

void Player::update(int dt){

	if (getAnimation())
	AnimatedSprite::update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		if (SDL_GetTicks() - timeSinceLastShot > 300)
		{
		Shoot();
			timeSinceLastShot = SDL_GetTicks();
	}

	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		AnimatedSprite::setAnimation("run");
		animationFlip = true;
		AnimatedSprite::getAnimation()->setFlip(animationFlip);
		if (!(_x > w - 65))
			setPosition(getX() + 2, getY());
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		AnimatedSprite::setAnimation("run");
		animationFlip = false;
		AnimatedSprite::getAnimation()->setFlip(animationFlip);
		if (!(_x < 1))
			setPosition(getX() - 2, getY());
	}

	if (!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		AnimatedSprite::setAnimation("idle");
		AnimatedSprite::getAnimation()->setFlip(animationFlip);
	}

	for (const auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

		if (static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
			std::cout << "Collision between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

			GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);

		}
	}
}

void Player::Shoot(){

	printf("Shooting missile from position %d:%d\n", _x, _y);

	Image missileImage("assets/bullet.png", true);
	Sprite* missile = new Missile(&missileImage, "a");

	missile->setPosition(_x + (_w / 2) - 4, _y - 15);



	missile->toggle_collidable();
	GameEngine::getInstance()->getStateManager()->getCurrentState()->addGameObject(missile);
}

