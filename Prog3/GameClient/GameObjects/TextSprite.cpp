#include "../../GameEngine/GameEngine.h"
#include "TextSprite.h"


TextSprite::TextSprite(const char* msg, SDL_Color text, SDL_Color clear) :message(msg), textColor(text), clearColor(clear)
{
}

void TextSprite::render(){

	GameEngine* world = GameEngine::getInstance();

	//SDL_Color textColor = { 255, 255, 255, 0 };

	SDL_Surface* messageSurface = TTF_RenderText_Solid(world->getFont(), message.c_str(), textColor);
	SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(world->getRenderer(), messageSurface);

	int text_width = messageSurface->w;
	int text_height = messageSurface->h;
	SDL_FreeSurface(messageSurface);

	SDL_Rect scoreRenderQuad = { getX(), getY(), text_width, text_height };

	SDL_Rect clearQuad = { getX(), getY(), text_width, text_height };

	//SDL_SetRenderDrawColor(world->getRenderer(), 0, 0, 0, 0);
	SDL_SetRenderDrawColor(world->getRenderer(), clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	SDL_RenderFillRect(world->getRenderer(), &clearQuad);

	SDL_RenderCopy(world->getRenderer(), messageTexture, NULL, &scoreRenderQuad);
	SDL_DestroyTexture(messageTexture);
}