#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Animation.h"
#include <string>
#include <map>

class Sprite :public GameObject {

public:

	Sprite(const char* filename);
	Sprite(Animation* a);
	Sprite();
	~Sprite();

	virtual void render();

	virtual void update();
	virtual void update(int dt){}

	void addAnimation(std::string name, Animation* a);
	void setAnimation(const char *name);
	Animation* getAnimation();
	
private:
	SDL_Texture* texture;
		
	std::map<std::string, Animation*> animations;
	Animation* currentAnimation;
	
	int animationTick;

protected:
};

