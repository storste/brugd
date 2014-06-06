#include "Animation.h"
#include "GameEngine.h"
#include <SDL_image.h>

void Animation::setPosition(int x, int y){
	destinationRectangle.x = x;
	destinationRectangle.y = y;
}

Animation::Animation(const char* filename, int frameWidth, int frameHeight, int frameCount, int framesPerRow) :flip(false), frameCount(frameCount), frameWidth(frameWidth), frameHeight(frameHeight), framesPerRow(framesPerRow)
{
	texture = IMG_LoadTexture(GameEngine::getInstance()->getRenderer(), filename);

	sourceRectangle.w = frameWidth;
	sourceRectangle.h = frameHeight;

	destinationRectangle.x = sourceRectangle.x = 0;
	destinationRectangle.y = sourceRectangle.y = 0;
	destinationRectangle.w = sourceRectangle.w;
	destinationRectangle.h = sourceRectangle.h;
}

Animation::~Animation()
{
}

void Animation::playAnimation(int dt) {
	//currentFrame = int(((SDL_GetTicks() / 30) % frameCount));
	currentFrame = int(((dt) % frameCount));
	//		std::cout << currentFrame << std::endl;
	sourceRectangle.x = frameWidth * (currentFrame % framesPerRow);
	sourceRectangle.y = frameHeight * (currentFrame / framesPerRow);
}

void Animation::renderAnimation(int x, int y){

	destinationRectangle.x = x;
	destinationRectangle.y = y;

	if (flip) {
		SDL_RenderCopyEx(GameEngine::getInstance()->getRenderer(), texture,
			&sourceRectangle, &destinationRectangle,
			0, 0, SDL_FLIP_HORIZONTAL); // pass in the horizontal flip
	}
	else {
		SDL_RenderCopy(GameEngine::getInstance()->getRenderer(), texture, &sourceRectangle,
			&destinationRectangle);
	}
}

void Animation::setFlip(bool b){
	flip = b;
}