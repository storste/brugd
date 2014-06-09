#pragma once
#include "Animation.h"
#include "Sprite.h"
#include <map>

class AnimatedSprite :public Sprite {

public:
	static AnimatedSprite* getInstance();
	static AnimatedSprite* getInstance(const std::string name);

	void addAnimation(const std::string name, Animation* a);
	void setAnimation(const std::string name);
	Animation* getAnimation();
	void render();
	void update();

private:
	std::map<std::string, Animation*> m_animations;
	Animation* m_currentAnimation;
	int m_animationTick;
	AnimatedSprite(const AnimatedSprite& other);
	const AnimatedSprite& operator=(const AnimatedSprite& other);

protected:
	AnimatedSprite(const std::string name);
	AnimatedSprite();
};