#pragma once
#include "SDL.h"
#include <string>

class Animation {
public:
	Animation(std::string filename, int frameWidth, int frameHeight, int frameCount, int framesPerRow, int yOffset);
	~Animation();
	void setPosition(int x, int y);
	void playAnimation(int dt);
	void renderAnimation(int x, int y);
	void setFlip(bool b);
	int getW(){ return frameWidth; }
	int getH(){ return frameHeight; }

private:
	int currentFrame;
	SDL_Texture* texture = nullptr;

	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;
	int frameWidth;
	int frameHeight;
	bool flip = false;
	int frameCount;
	int framesPerRow;
	int yOffset;
};

