#include <iostream>
#include "Player.h"
#include "Explosion.h"
#include "../GameEngine/GameEngine.h"

Player* Player::getInstance(){
	return new Player();
}
Player::Player() : timeSinceLastShot(SDL_GetTicks()), w(800), h(600) {
}

Player::~Player(){
	//std::cout << "Player: Destructor" << std::endl;
}

void Player::update(int dt){

	if (getAnimation())
	AnimatedSprite::update();

	if (!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		setAnimation("idle");
		getAnimation()->setFlip(animationFlip);
	}

	for (auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){

		if (static_cast<GameObject*>(this) != o && o->getName() != "Intro background" && o->getName() != "hanna" && GameEngine::getInstance()->cd(this, o)){

			std::cout << "Collission between " << static_cast<GameObject*>(this)->getName() << " and " << o->getName() << std::endl;

			//o->doCollission();
			GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
			doCollission();
		}
	}
}

void Player::shoot(){

	if (SDL_GetTicks() - timeSinceLastShot > 300 && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
	Image missileImage("assets/bullet.png", true);
	Sprite* missile = new Missile(&missileImage, "a");

		missile->setPosition(getX() + (getW() / 2) - 4, getY() - 15);

	missile->toggle_collidable();
	GameEngine::getInstance()->getStateManager()->getCurrentState()->addGameObject(missile);
		timeSinceLastShot = SDL_GetTicks();
	}
}

void Player::moveRight(){
	setAnimation("run");
	animationFlip = true;
	getAnimation()->setFlip(animationFlip);
	if (!(_x > GameEngine::getInstance()->getWidth() - 65))
		setPosition(getX() + 2, getY());
}

void Player::doCollission(){
	
}

void Player::moveLeft(){
	setAnimation("run");
	animationFlip = false;
	getAnimation()->setFlip(animationFlip);
	if (!(_x < 1))
		setPosition(getX() - 2, getY());
}