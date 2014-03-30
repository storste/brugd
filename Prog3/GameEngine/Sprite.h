#pragma once
#include <SDL.h>
#include "Drawable.h"
#include <string>

class Sprite :public Drawable {
public:
	Sprite(const char* filename, SDL_Renderer* r);
	~Sprite();
	virtual void draw();
	virtual void setPosition(int x, int y);
	virtual void setName(std::string name){ m_name = name; }
	virtual std::string getName() const{ return m_name; }

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	int width;
	int height;
	int x;
	int y;
	std::string m_name;
};

