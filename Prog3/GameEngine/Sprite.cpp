#pragma once
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"
#include "../GameEngine/GameEngine.h"

Sprite::Sprite(Animation* a){

}

Sprite::Sprite(){

}

Sprite::Sprite(const char* filename, SDL_Renderer* r)
{
	renderer = r;
	texture = IMG_LoadTexture(renderer, filename);
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
int Sprite::getW(){ return width; }
int Sprite::getH(){ return height; }

void Sprite::render()
{

	if (currentAnimation){
		currentAnimation->renderAnimation();
	}

	else{

		if (!renderer)
			std::cout << "No renderer..." << std::endl;

		if (!texture)
			std::cout << "No texture..." << std::endl;

		SDL_Rect dst;
		SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
		dst.x = x; dst.y = y;

		SDL_RenderCopyEx(renderer, texture, NULL /*&src*/, &dst, 0.0, NULL, SDL_FLIP_NONE);
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
}

std::string Sprite::getName(){
	return m_name;
}

void Sprite::setName(const char * name){ m_name = name; }

Animation* Sprite::getAnimation(){ return currentAnimation; }