#pragma once
#include "SDL.h"

class Animation
{
public:
	Animation(const char* filename, SDL_Renderer* r, int frameWidth, int frameHeight, int frameCount, int framesPerRow);
	~Animation();
	void setPosition(int x, int y);
	void playAnimation(int dt);
	void renderAnimation();
private:
	int currentFrame;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;
	int frameWidth;
	int frameHeight;

	int frameCount;
	int framesPerRow;

};

