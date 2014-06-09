#pragma once
#include "AnimatedSprite.h"
#include <SDL_image.h>


AnimatedSprite* AnimatedSprite::getInstance(){
	return new AnimatedSprite();
}
AnimatedSprite* AnimatedSprite::getInstance(std::string name){
	return new AnimatedSprite(name);
}
AnimatedSprite::AnimatedSprite(std::string name){
	m_visible = true;
	//m_collidable = true;
	m_name = name;
}
AnimatedSprite::AnimatedSprite(){
	m_visible = true;
	m_collidable = true;
}
void AnimatedSprite::addAnimation(std::string name, Animation* a){
	std::pair<std::string, Animation*> pair = std::make_pair(name, a);
	m_animations.insert(pair);
}

void AnimatedSprite::setAnimation(std::string name){
	m_currentAnimation = m_animations[name];

	_w = m_currentAnimation->getW();
	_h = m_currentAnimation->getH();
}

Animation* AnimatedSprite::getAnimation()
{
	return m_currentAnimation;
}

void AnimatedSprite::render()
{
	m_currentAnimation->renderAnimation(_x, _y);
}


void AnimatedSprite::update(){

	if (m_currentAnimation){
		m_currentAnimation->setPosition(_x, _y);
		m_currentAnimation->playAnimation(m_animationTick);
		m_animationTick++;
	}
}
