#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <assert.h>
#include "Image.h"

//Konstruktor
Image::Image(SDL_Surface* surface) : m_surface(surface){ 
	if (m_surface)
		m_surface->refcount++;
	std::cout << "Image: Constructor 1: " << m_surface->refcount << std::endl;
}

//Konstruktor 2
Image::Image(std::string path, bool alpha) : m_path(path), m_alpha(alpha){
	m_surface = IMG_Load(m_path.c_str());
	
	//if (theImage)
	//	theImage->refcount++;
	std::cout << "Image: Constructor 2: " << m_surface->refcount << std::endl;
}

//Copy konstruktor
Image::Image(const Image& other) :m_surface(other.m_surface){
	
	if (m_surface)
		m_surface->refcount++;
	std::cout << "Image: Copy Constructor: " << m_surface->refcount << std::endl;
}

//Tilldelningsoperator
const Image& Image::operator=(const Image& other){
	
	if (m_surface != other.m_surface){
		if (m_surface)
			SDL_FreeSurface(m_surface);
		m_surface = other.m_surface;
		m_surface->refcount++;
		std::cout << "Image: Assignment Constructor: " << m_surface->refcount << std::endl;
	}
	return *this;
}

//Destruktor
Image::~Image(){
	if (m_surface){
		SDL_FreeSurface(m_surface);
		if (m_surface->refcount == 0)
			std::cout << "Image: Destructor (deleted all): " << m_surface->refcount << std::endl;
	}
}
