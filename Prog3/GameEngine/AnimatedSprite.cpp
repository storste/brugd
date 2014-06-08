#pragma once
#include "AnimatedSprite.h"
#include <SDL_image.h>


AnimatedSprite* AnimatedSprite::getInstance(){
	return new AnimatedSprite();
}

AnimatedSprite* AnimatedSprite::getInstance(const std::string name){
	return new AnimatedSprite(name);
}

AnimatedSprite::AnimatedSprite(const std::string name){

	toggle_collidable();
	setName(name);
}

AnimatedSprite::AnimatedSprite(){

	toggle_collidable();
}

void AnimatedSprite::addAnimation(const std::string name, Animation* a){
	std::pair<const std::string, Animation*> pair = std::make_pair(name, a);
	m_animations.insert(pair);
}

void AnimatedSprite::setAnimation(const std::string name){
	m_currentAnimation = m_animations[name];

	setW(m_currentAnimation->getW());
	setH(m_currentAnimation->getH());
}

Animation* AnimatedSprite::getAnimation()
{
	return m_currentAnimation;
}

void AnimatedSprite::render()
{
	m_currentAnimation->renderAnimation(getX(), getY());
}


void AnimatedSprite::update(){

	if (m_currentAnimation){
		m_currentAnimation->setPosition(getX(), getY());
		m_currentAnimation->playAnimation(m_animationTick);
		m_animationTick++;
	}
}
