#pragma once
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"
#include "GameEngine.h"
#include <assert.h>

Sprite::Sprite(){
	m_visible = true;
}


Sprite::Sprite(std::string filename, std::string name) :Sprite(filename){
	m_name = name;
	m_visible = true;
}

Sprite::Sprite(Image* i, std::string name) : m_image(i){
	m_texture = SDL_CreateTextureFromSurface(GameEngine::getInstance()->getRenderer(), m_image->getSurface());
	SDL_QueryTexture(m_texture, NULL, NULL, &_w, &_h);
	m_name = name;
	m_visible = true;
	m_collidable = true;
}

Sprite::Sprite(std::string filename)
{
	m_texture = IMG_LoadTexture(GameEngine::getInstance()->getRenderer(), filename.c_str());
	SDL_QueryTexture(m_texture, NULL, NULL, &_w, &_h);

	m_collidable = true;
	m_visible = true;
}

void Sprite::render()
{
		SDL_Rect dst;
		SDL_QueryTexture(m_texture, NULL, NULL, &dst.w, &dst.h);
		dst.x = _x; dst.y = _y;

		SDL_RenderCopyEx(GameEngine::getInstance()->getRenderer(), m_texture, NULL /*&src*/, &dst, 0.0, NULL, SDL_FLIP_NONE);
	
	}

void Sprite::update(){
}

