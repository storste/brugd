#pragma once
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"
#include "../GameEngine/GameEngine.h"

Sprite::Sprite(Animation* a){
	w = a->w();
	h = a->h();
}

Sprite::Sprite(){

}

Sprite::Sprite(const char* filename) 
{
	texture = IMG_LoadTexture(GameEngine::getInstance()->getRenderer(), filename);
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	std::cout << "setting w & h for sprite" << std::endl;
}


Sprite::~Sprite()
{
}

void Sprite::setPosition(int x_pos, int y_pos){
	x = x_pos;
	y = y_pos;
}

int Sprite::getY(){ return y; }
int Sprite::getX(){ return x; }
int Sprite::getW(){ return w; }
int Sprite::getH(){ return h; }

void Sprite::render()
{
	if (currentAnimation){
		currentAnimation->renderAnimation();
	}
	else {

		//if (!renderer)
		//	std::cout << "No renderer..." << std::endl;

		//if (!texture)
		//	std::cout << "No texture..." << std::endl;

		SDL_Rect dst;
		SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
		dst.x = x; dst.y = y;

		SDL_RenderCopyEx(GameEngine::getInstance()->getRenderer(), texture, NULL /*&src*/, &dst, 0.0, NULL, SDL_FLIP_NONE);
	}
}

void Sprite::update(int dt){

	if (currentAnimation){

		currentAnimation->setPosition(x, y);
		currentAnimation->playAnimation(dt);
	}
}

void Sprite::addAnimation(std::string name, Animation* a){
	std::pair<std::string, Animation*> pair = std::make_pair(name, a);
	animations.insert(pair);
}

void Sprite::setAnimation(const char *name){
	currentAnimation = animations[name];
	
	w = currentAnimation->w();
	h = currentAnimation->h();
	std::cout << "setting w & h for sprite" << std::endl;
}

const std::string Sprite::getName(){
	return m_name;
}

void Sprite::setName(const char * name)
{
	m_name = name;
	}

Animation* Sprite::getAnimation()
{
	return currentAnimation;
}