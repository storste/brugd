#include <iostream>
#include "Player.h"
#include "../GameEngine/GameEngine.h"

//Player::Player(std::string filename, std::string name) :Sprite(filename, name), timeSinceLastShot(SDL_GetTicks()), w(640), h(480)
//{
//}
Player* Player::getInstance(){
	return new Player();
}
Player::Player() : timeSinceLastShot(SDL_GetTicks()), w(640), h(480) {
	std::cout << "im alive!";
}

Player::~Player(){
	//std::cout << "Player: Destructor" << std::endl;
}

void Player::update(int dt){

	if (getAnimation())
	AnimatedSprite::update();

	if (!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		AnimatedSprite::setAnimation("idle");
		AnimatedSprite::getAnimation()->setFlip(animationFlip);
	}

	for (const auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

		if (static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
			//std::cout << "Collision between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

			GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);

		}
	}
}

void Player::shoot(){

	if (SDL_GetTicks() - timeSinceLastShot > 300)
	{
	Image missileImage("assets/bullet.png", true);
	Sprite* missile = new Missile(&missileImage, "a");

	missile->setPosition(_x + (_w / 2) - 4, _y - 15);

	missile->toggle_collidable();
	GameEngine::getInstance()->getStateManager()->getCurrentState()->addGameObject(missile);
		timeSinceLastShot = SDL_GetTicks();
	}
}

void Player::moveRight(){
	Sprite::setAnimation("run");
	animationFlip = true;
	Sprite::getAnimation()->setFlip(animationFlip);
	if (!(_x > w - 65))
		setPosition(getX() + 2, getY());
}

void Player::doCollission(){
	std::cout << "Player: doCollission()" << std::endl;
}

void Player::moveLeft(){
	Sprite::setAnimation("run");
	animationFlip = false;
	Sprite::getAnimation()->setFlip(animationFlip);
	if (!(_x < 1))
		setPosition(getX() - 2, getY());
}