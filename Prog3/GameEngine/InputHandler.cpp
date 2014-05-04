#include "InputHandler.h"
#include "GameEngine.h"

InputHandler* InputHandler::instance;

InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

void InputHandler::update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			GameEngine::getEngineInstance()->quit();
		}
	}
}