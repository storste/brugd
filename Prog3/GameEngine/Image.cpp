#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include "imageOld.h"

//Konstruktor
ImageOld::ImageOld(SDL_Surface* i) : theImageOld(i){ 
	if (theImageOld)
		theImageOld->refcount++;
	std::cout << "def konstru: " << theImageOld->refcount << std::endl;
}
//Konstruktor 2
ImageOld::ImageOld(std::string p, bool b) : path(p), isAlpha(b){
	theImageOld = SDL_LoadBMP(path.c_str());
	//if (theImageOld)
	//	theImageOld->refcount++;
	std::cout << "sec konstru: " << theImageOld->refcount << std::endl;
}
//Copy konstruktor
ImageOld::ImageOld(const ImageOld& other) :theImageOld(other.theImageOld){
	if (theImageOld)
		theImageOld->refcount++;
	std::cout << "copy konstru: " << theImageOld->refcount << std::endl;
}
//Tilldelningsoperator
const ImageOld& ImageOld::operator=(const ImageOld& other){
	if (theImageOld != other.theImageOld){
		if (theImageOld)
			SDL_FreeSurface(theImageOld);
		theImageOld = other.theImageOld;
		theImageOld->refcount++;
		std::cout << "tilldel: " << theImageOld->refcount << std::endl;
	}
	return *this;
}
//Detruktor
ImageOld::~ImageOld(){
	if (theImageOld){
		SDL_FreeSurface(theImageOld);
		std::cout << "Ref--: " << theImageOld->refcount << std::endl;
		if (theImageOld->refcount == 0)
			std::cout << "delete: " << theImageOld->refcount << std::endl;
	}
}
