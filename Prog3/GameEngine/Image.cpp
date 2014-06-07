#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Image.h"

//Konstruktor
Image::Image(SDL_Surface* i) : theImage(i){ 
	if (theImage)
		theImage->refcount++;
	std::cout << "def konstru: " << theImage->refcount << std::endl;
}
//Konstruktor 2
Image::Image(std::string p, bool b) : path(p), isAlpha(b){
	theImage = IMG_Load(path.c_str());
	//if (theImage)
	//	theImage->refcount++;
	std::cout << "sec konstru: " << theImage->refcount << std::endl;
}
//Copy konstruktor
Image::Image(const Image& other) :theImage(other.theImage){
	if (theImage)
		theImage->refcount++;
	std::cout << "copy konstru: " << theImage->refcount << std::endl;
}
//Tilldelningsoperator
const Image& Image::operator=(const Image& other){
	if (theImage != other.theImage){
		if (theImage)
			SDL_FreeSurface(theImage);
		theImage = other.theImage;
		theImage->refcount++;
		std::cout << "tilldel: " << theImage->refcount << std::endl;
	}
	return *this;
}
//Detruktor
Image::~Image(){
	if (theImage){
		SDL_FreeSurface(theImage);
		std::cout << "Ref--: " << theImage->refcount << std::endl;
		if (theImage->refcount == 0)
			std::cout << "delete: " << theImage->refcount << std::endl;
	}
}
