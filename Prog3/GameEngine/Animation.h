#pragma once
#include "SDL.h"

class Animation
{
public:
	Animation(const char* filename, int frameWidth, int frameHeight, int frameCount, int framesPerRow);
	~Animation();
	void setPosition(int x, int y);
	void playAnimation(int dt);
	void renderAnimation(int x, int y);
	void setFlip(bool b);
	int getW(){ return frameWidth; }
	int getH(){ return frameHeight; }

private:
	int currentFrame;
	SDL_Texture* texture;
	
	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;
	int frameWidth;
	int frameHeight;
	bool flip;
	int frameCount;
	int framesPerRow;
};

