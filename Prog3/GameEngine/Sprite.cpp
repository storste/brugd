#pragma once
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"



Sprite::Sprite(const char* filename, SDL_Renderer* r)
{
	renderer = r;
	texture = IMG_LoadTexture(renderer, filename);

	m_sourceRectangle.w = 130;
	m_sourceRectangle.h = 150;

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;


}


Sprite::~Sprite()
{
}

void Sprite::setPosition(int x_pos, int y_pos){
	x = x_pos;
	y = y_pos;
}

void Sprite::render()
{
	if (!renderer)
		std::cout << "No renderer..." << std::endl;

	if (!texture)
		std::cout << "No texture..." << std::endl;

	SDL_RenderCopy(renderer, texture, &m_sourceRectangle,
		&m_destinationRectangle);

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
void Sprite::update(){
	currentFrame = int(((SDL_GetTicks() / 30) % 27));
	std::cout << currentFrame << std::endl;
	m_sourceRectangle.x = 130 * (currentFrame % 7);
	m_sourceRectangle.y = 150 * (currentFrame / 7);

}