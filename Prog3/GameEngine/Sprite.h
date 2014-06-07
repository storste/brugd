#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Animation.h"
#include "Image.h"
#include <string>
#include <map>

class Sprite :public GameObject {

public:

	Sprite* getSprite(){
		return new Sprite();
	}

	Sprite(const char* filename);
	Sprite(const char* filename, const char * name);
	Sprite(Image* i, const char * name);
	Sprite(Animation* a);
	Sprite();

	virtual ~Sprite() = default;

	virtual void render();

	virtual void update();
	virtual void update(int dt){}

	virtual void doCollission(){ std::cout << "Sprite: doCollission()" << std::endl; };

	void addAnimation(std::string name, Animation* a);
	void setAnimation(const char *name);
	Animation* getAnimation();

private:
	Image* image;
	SDL_Texture* texture;

	std::map<std::string, Animation*> animations;
	Animation* currentAnimation;

	int animationTick;

protected:
};

	