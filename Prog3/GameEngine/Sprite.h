#pragma once
#include <SDL.h>
#include "GameObject.h"
#include <string>

class Sprite :public GameObject {
public:
	Sprite(const char* filename, SDL_Renderer* r);
	~Sprite();
	virtual void render();
	virtual void setPosition(int x, int y);
	virtual void setName(std::string name){ m_name = name; }
	virtual std::string getName() const{ return m_name; }
	virtual void update();

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	int width;
	int height;
	int x;
	int y;
	std::string m_name;


	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // another rectangle
	int currentFrame;

};

