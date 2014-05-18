#pragma once
#include "SDL.h"
#include "GameEngine.h"


class InputHandler
{
public:
	void update();
	static InputHandler* Instance()
	{
		if (instance == 0)
		{
			instance = new InputHandler();
		}
		return instance;
	}
	bool InputHandler::isKeyDown(SDL_Scancode key);

private:
	InputHandler();
	~InputHandler();
	void onKeyDown();
	void onKeyUp();
	const Uint8* keystates;
	static InputHandler* instance;
};

