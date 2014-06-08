#pragma once
#include "SDL.h"

class InputHandler
{
public:

	static InputHandler* Instance()
	{
		if (instance == nullptr)
		{
			instance = new InputHandler();
		}
		return instance;
	}

	bool isKeyDown(SDL_Scancode key);
	void update();

private:
	InputHandler();
	~InputHandler();
	InputHandler(const InputHandler& other);
	const InputHandler& operator=(const InputHandler& other);
	void onKeyDown();
	void onKeyUp();
	const Uint8* keystates;
	static InputHandler* instance;
};

