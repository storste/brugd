#include "ScoreSprite.h"


ScoreSprite::ScoreSprite()
{
}

void ScoreSprite::render(){

	GameEngine* world = GameEngine::getInstance();

	SDL_Color textColor = { 255, 255, 255, 0 };

	std::string score_text = "Score: " + std::to_string(world->getScore());
	std::string level_text = "Level: " + std::to_string(world->getStateManager()->getCurrentState()->getLevel());

	SDL_Surface* scoreTextSurface = TTF_RenderText_Solid(world->getFont(), score_text.c_str(), textColor);
	SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(world->getRenderer(), scoreTextSurface);

	SDL_Surface* levelTextSurface = TTF_RenderText_Solid(world->getFont(), level_text.c_str(), textColor);
	SDL_Texture* levelTexture = SDL_CreateTextureFromSurface(world->getRenderer(), levelTextSurface);

	int score_text_width = scoreTextSurface->w;
	int score_text_height = scoreTextSurface->h;
	SDL_FreeSurface(scoreTextSurface);

	int level_text_width = levelTextSurface->w;
	int level_text_height = levelTextSurface->h;
	SDL_FreeSurface(levelTextSurface);

	SDL_Rect scoreRenderQuad = { 20, world->getCanvasHeight() - 50, score_text_width, score_text_height };
	SDL_Rect levelRenderQuad = { world->getScreenWidth() - score_text_width - 20, world->getCanvasHeight() - 50, score_text_width, score_text_height };

	SDL_Rect clearQuad = { 0, world->getCanvasHeight() - 100, world->getScreenWidth(), 100 };

	SDL_SetRenderDrawColor(world->getRenderer(), 0, 0, 0, 0);
	SDL_RenderFillRect(world->getRenderer(), &clearQuad);

	SDL_RenderCopy(world->getRenderer(), scoreTexture, NULL, &scoreRenderQuad);
	SDL_DestroyTexture(scoreTexture);

	SDL_RenderCopy(world->getRenderer(), levelTexture, NULL, &levelRenderQuad);
	SDL_DestroyTexture(levelTexture);
}