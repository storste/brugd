#include "Animation.h"
#include <SDL_image.h>

void Animation::setPosition(int x, int y){
	destinationRectangle.x = x;
	destinationRectangle.y = y;
}

Animation::Animation(const char* filename, SDL_Renderer* r, int frameWidth, int frameHeight, int frameCount, int framesPerRow)
:frameCount(frameCount), frameWidth(frameWidth), frameHeight(frameHeight), framesPerRow(framesPerRow)
{
	renderer = r;
	texture = IMG_LoadTexture(renderer, filename);

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

void Animation::playAnimation() {
	currentFrame = int(((SDL_GetTicks() / 30) % frameCount));
	//		std::cout << currentFrame << std::endl;
	sourceRectangle.x = frameWidth * (currentFrame % framesPerRow);
	sourceRectangle.y = frameHeight * (currentFrame / framesPerRow);
}

void Animation::renderAnimation(){
	SDL_RenderCopy(renderer, texture, &sourceRectangle,
		&destinationRectangle);

}