#include <SDL.h>
#include <iostream>
#include <string>
#include <SDL_image.h>
#include "GameEngine.h"

class Image2{
public:
	Image2(SDL_Texture* i = 0);
	Image2(std::string p, bool b);
	Image2(const Image2& other);
	const Image2& operator=(const Image2& other);
	SDL_Texture* getSurface() const { return theImage; }
	~Image2();
private:
	SDL_Texture* theImage;
	bool isAlpha;
	std::string path;
	int refcount;
};
//Konstruktor
Image2::Image2(SDL_Texture* i) : theImage(i){
	if (theImage)
		refcount++;
	std::cout << "def konstru: " << refcount;
}
//Konstruktor 2
Image2::Image2(std::string p, bool b) : path(p), isAlpha(b){
	theImage = IMG_LoadTexture(GameEngine::getInstance()->getRenderer(),path.c_str());
	//if (theImage)
	//	theImage->refcount++;
	std::cout << "sec konstru: " << refcount;
}
//Copy konstruktor
Image2::Image2(const Image2& other) :theImage(other.theImage){
	if (theImage)
		refcount++;
	std::cout << "copy konstru: " << refcount;
}
//Tilldelningsoperator
const Image2& Image2::operator=(const Image2& other){
	if (theImage != other.theImage){
		if (theImage)
			SDL_DestroyTexture(theImage);
		theImage = other.theImage;
		refcount++;
		std::cout << "tilldel: " << refcount;
	}
	return *this;
}
//Detruktor
Image2::~Image2(){
	if (theImage){
		SDL_DestroyTexture(theImage);
		if (refcount == 0)
			std::cout << "delete: " << refcount;
	}
}
