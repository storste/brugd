#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>
#include <string>
#include <SDL_image.h>

class Image{

public:
	Image(SDL_Surface* i = nullptr);
	Image(std::string path, bool alpha);
	Image(const Image& other);
	const Image& operator=(const Image& other);
	SDL_Surface* getSurface() const { return m_surface; }
	~Image();

private:
	SDL_Surface* m_surface;
	bool m_alpha;
	std::string m_path;
};

#endif