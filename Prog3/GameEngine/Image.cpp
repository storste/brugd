#include <SDL.h>
#include <iostream>
#include <string>

class Image{
public:
	Image(SDL_Surface* i = 0);
	Image(std::string p, bool b);
	Image(const Image& other);
	const Image& operator=(const Image& other);
	SDL_Surface* getSurface() const{return theImage; }
	~Image();
private:
	SDL_Surface* theImage;
	bool isAlpha;
	std::string path;
};
Image::Image(SDL_Surface* i) : theImage(i){
	if (theImage)
		theImage->refcount++;
	std::cout << "def k: "<< theImage->refcount;
}
Image::Image(std::string p, bool b) : path(p), isAlpha(b){
	theImage = SDL_LoadBMP(path.c_str());
	//if (theImage)
	//	theImage->refcount++;
	std::cout << "sec k ; " << theImage->refcount;
}


Image::Image(const Image& other) :theImage(other.theImage){
	if (theImage)
		theImage->refcount++;
	std::cout << "copy : " << theImage->refcount;
}
const Image& Image::operator=(const Image& other){
	if (theImage != other.theImage){
		if (theImage)
			SDL_FreeSurface(theImage);
		theImage == other.theImage;
		theImage->refcount++;
		std::cout <<"tiil : " << theImage->refcount;
	}
	return *this;
}
Image::~Image(){
	if (theImage){
		SDL_FreeSurface(theImage);
		if (theImage->refcount == 0)
		std::cout << " delete " << theImage->refcount;
	}
}


