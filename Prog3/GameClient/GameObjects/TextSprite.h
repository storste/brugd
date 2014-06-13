#ifndef TEXTSPRITE_H
#define TEXTSPRITE_H

#include "../../GameEngine/Sprite.h"

class TextSprite :
	public Sprite {
public:
	TextSprite(const char* text, SDL_Color, SDL_Color);
	void render();
private:
	std::string message;
	SDL_Color textColor;
	SDL_Color clearColor;
};

#endif