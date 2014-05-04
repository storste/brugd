#include <SDL.h>
#include <iostream>
#include "Game.h"

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
SDL_Texture* m_pTexture; // the new SDL_Texture variable
SDL_Rect m_sourceRectangle; // the first rectangle
SDL_Rect m_destinationRectangle; // another rectangle

int main(int argc, char** argv){

	Game* g_game = 0;

	{
		g_game = new Game();
		if (g_game->init("Chapter 1", 100, 100, 640, 480, false))
		while (g_game->running())
		{
			g_game->handleEvents();
			g_game->update();
			g_game->render();
		}
		g_game->clean();
		return 0;
	}

}



