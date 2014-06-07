#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Animation.h"
#include <string>
#include <map>

class Sprite :public GameObject {

public:

	Sprite(const char* filename);
	Sprite(const char* filename, const char * name);
	Sprite(Animation* a);
	Sprite();

	virtual ~Sprite() = default;

	virtual void Render();

	virtual void Update();
	virtual void Update(int dt){}

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

