#pragma once
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"
#include "GameEngine.h"

Sprite::Sprite(Animation* a){
	_w = a->getW();
	_h = a->getH();
	_visible = true;
}

Sprite::Sprite(){
	_visible = true;
}

Sprite::Sprite(const char* filename, const char * name) :Sprite(filename){
	_name = name;
	_visible = true;
}

Sprite::Sprite(const char* filename)
{
	texture = IMG_LoadTexture(GameEngine::getInstance()->getRenderer(), filename);
	SDL_QueryTexture(texture, NULL, NULL, &_w, &_h);

	animationTick = 0;
	_collidable = true;
	_visible = true;
}

void Sprite::Render()
{
	if (currentAnimation){
		currentAnimation->renderAnimation(_x, _y);
	}
	else {

		SDL_Rect dst;
		SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
		dst.x = _x; dst.y = _y;

		SDL_RenderCopyEx(GameEngine::getInstance()->getRenderer(), texture, NULL /*&src*/, &dst, 0.0, NULL, SDL_FLIP_NONE);
	}
}

void Sprite::Update(){

	if (currentAnimation){
		//std::cout << animationTick << std::endl;
		currentAnimation->setPosition(_x, _y);
		currentAnimation->playAnimation(animationTick);
		animationTick++;
	}
}

void Sprite::addAnimation(std::string name, Animation* a){
	std::pair<std::string, Animation*> pair = std::make_pair(name, a);
	animations.insert(pair);
}

void Sprite::setAnimation(const char *name){
	currentAnimation = animations[name];

	_w = currentAnimation->getW();
	_h = currentAnimation->getH();
}


Animation* Sprite::getAnimation()
{
	return currentAnimation;
}