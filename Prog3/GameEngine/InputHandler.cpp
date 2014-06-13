
#include "InputHandler.h"
#include "GameEngine.h"
#include "SDL.h"

InputHandler* InputHandler::instance;

InputHandler::InputHandler() : keystates(0)
{
}

InputHandler::~InputHandler()
{
}

void InputHandler::update()
{
	////std::cout << "InputHandler: update" << std::endl;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			GameEngine::getInstance()->quit();
			break;

		case SDL_KEYDOWN:
			onKeyDown();
			break;

		case SDL_KEYUP:
			onKeyUp();
			break;

		default:
			break;
		}
	}
}

void InputHandler::onKeyDown()
{
	keystates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
	keystates = SDL_GetKeyboardState(0);
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{	
	return (keystates && keystates[key] == 1 ? true : false);
}