#include <SDL.h>
#include <iostream>
#include <string>
#include <SDL_image.h>
#include "GameEngine.h"

class ImageOld{
public:
	ImageOld(SDL_Surface* i = 0);
	ImageOld(std::string p, bool b);
	ImageOld(const ImageOld& other);
	const ImageOld& operator=(const ImageOld& other);
	SDL_Surface* getSurface() const { return theImageOld; }
	~ImageOld();
private:
	SDL_Surface* theImageOld;
	bool isAlpha;
	std::string path;
};