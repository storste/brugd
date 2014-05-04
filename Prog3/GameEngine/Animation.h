#pragma once
#include "SDL.h"

class Animation
{
public:
	Animation(const char* filename, SDL_Renderer* r, int frameWidth, int frameHeight, int frameCount, int framesPerRow);
	~Animation();

	void playAnimation();
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

/*
currentFrame = int(((SDL_GetTicks() / 30) % 27));
std::cout << currentFrame << std::endl;
m_sourceRectangle.x = 130 * (currentFrame % 7);
m_sourceRectangle.y = 150 * (currentFrame / 7);
*/