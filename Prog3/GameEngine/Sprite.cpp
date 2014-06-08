#pragma once
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"
#include "GameEngine.h"
#include <assert.h>

Sprite::Sprite(Animation* a){
	_w = a->getW();
	_h = a->getH();
	m_visible = true;
}

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

	m_animationTick = 0;
	m_collidable = true;
	m_visible = true;
}

void Sprite::render()
{
	if (m_currentAnimation){
		m_currentAnimation->renderAnimation(_x, _y);
	}
	else {

		SDL_Rect dst;
		SDL_QueryTexture(m_texture, NULL, NULL, &dst.w, &dst.h);
		dst.x = _x; dst.y = _y;

		SDL_RenderCopyEx(GameEngine::getInstance()->getRenderer(), m_texture, NULL /*&src*/, &dst, 0.0, NULL, SDL_FLIP_NONE);
	}
}

void Sprite::update(){

	if (m_currentAnimation){
		//std::cout << animationTick << std::endl;
		m_currentAnimation->setPosition(_x, _y);
		m_currentAnimation->playAnimation(m_animationTick);
		m_animationTick++;
	}
}

void Sprite::addAnimation(std::string name, Animation* a){
	std::pair<std::string, Animation*> pair = std::make_pair(name, a);
	m_animations.insert(pair);
}

void Sprite::setAnimation(std::string name){
	m_currentAnimation = m_animations[name];

	_w = m_currentAnimation->getW();
	_h = m_currentAnimation->getH();
}

Animation* Sprite::getAnimation()
{
	return m_currentAnimation;
}