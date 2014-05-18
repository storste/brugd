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

	}


	//SDL_Rect src;
	//src.h = 32; src.w = 32;
	//src.x = x * 32;	src.y = y * 32;

	//SDL_Rect dst;
	//dst.h = 32; dst.w = 32;
	//dst.x = x; dst.y = y;

	//SDL_RenderCopyEx(renderer, texture, NULL /*&src*/, &dst, 0.0, NULL, SDL_FLIP_NONE);

	////SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	//std::cout << "Rendering dot" << std::endl;

}

void Sprite::update(int dt){

	currentAnimation->setPosition(x, y);
	currentAnimation->playAnimation(dt);

}