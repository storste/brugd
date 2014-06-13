#include "../../GameEngine/GameEngine.h"
#include "Missile.h"

#include <iostream>
#include "Player.h"

Player* Player::getInstance(){
	return new Player();
}

Player::Player() : timeSinceLastShot(SDL_GetTicks()), w(800), h(600) {
	//std::cout << "Player: Constructor" << std::endl;
}


void Player::update(int dt){

	if (getAnimation())
	AnimatedSprite::update();

	if (!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		setAnimation("idle");
		getAnimation()->setFlip(animationFlip);
	}

	for (const auto& o : GameEngine::getInstance()->getStateManager()->getCurrentState()->getObjects()){
		if (o){
			if (static_cast<GameObject*>(this) != o && o->is_collidable() && GameEngine::getInstance()->cd(this, o)){
			GameEngine::getInstance()->getStateManager()->getCurrentState()->removeGameObject(o);
			}
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
	if (!(getX() > GameEngine::getInstance()->getScreenWidth() - 65))
		setPosition(getX() + 2, getY());
}

void Player::doCollission(){
	
}

void Player::moveLeft(){
	setAnimation("run");
	animationFlip = false;
	getAnimation()->setFlip(animationFlip);
	if (!(getX() < 1))
		setPosition(getX() - 2, getY());
}