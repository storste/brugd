#pragma once
#include "Animation.h"
#include "Sprite.h"
#include <map>

class AnimatedSprite :public Sprite {

public:
	static AnimatedSprite* getInstance();
	static AnimatedSprite* getInstance(std::string name);

	void addAnimation(std::string name, Animation* a);
	void setAnimation(std::string name);
	Animation* getAnimation();
	virtual void render();
	virtual void update();
	friend class Sprite;

private:
	std::map<std::string, Animation*> m_animations;
	Animation* m_currentAnimation;
	int m_animationTick;

protected:
	AnimatedSprite(std::string name);
	AnimatedSprite();
};