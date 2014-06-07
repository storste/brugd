#pragma once 
#include <SDL.h>
#include <iostream>
#include <string>
#include <SDL_image.h>

class Image{
public:
	Image(SDL_Surface* i = 0);
	Image(std::string p, bool b);
	Image(const Image& other);
	const Image& operator=(const Image& other);
	SDL_Surface* getSurface() const { return theImage; }
	~Image();
private:
	SDL_Surface* theImage;
	bool isAlpha;
	std::string path;
};