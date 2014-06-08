#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Image.h"
#include <string>


class Sprite :public GameObject {

public:

	Sprite* getSprite(){
		return new Sprite();
	}

	Sprite(std::string filename);
	Sprite(std::string filename, std::string name);
	Sprite(Image* i, std::string name);
	Sprite();

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
};

	