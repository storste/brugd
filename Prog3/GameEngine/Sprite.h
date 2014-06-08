#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Image.h"
#include <string>


class Sprite :public GameObject {

public:
	static Sprite* getInstance();
	static Sprite* getInstance(Image* i, std::string name);
	virtual ~Sprite() = default;

	virtual void render();
	virtual void update();
	virtual void update(int dt){}

	virtual void doCollission(){ //std::cout << "Sprite: doCollission()" << std::endl; 
	};

private:
	Image* m_image;
	SDL_Texture* m_texture;

protected:
	Sprite(Image* i, std::string name);
	Sprite();
};

	