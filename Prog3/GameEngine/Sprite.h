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

	Sprite(std::string filename);
	Sprite(std::string filename, std::string name);
	Sprite(Image* i, std::string name);
	Sprite(Animation* a);
	Sprite();

	virtual ~Sprite() = default;

	virtual void render();

	virtual void update();
	virtual void update(int dt){}

	virtual void doCollission(){ std::cout << "Sprite: doCollission()" << std::endl; };

	void addAnimation(std::string name, Animation* a);
	void setAnimation(std::string name);
	Animation* getAnimation();

private:
	Image* m_image;
	SDL_Texture* m_texture;

	std::map<std::string, Animation*> m_animations;
	Animation* m_currentAnimation;

	int m_animationTick;

protected:
};

	