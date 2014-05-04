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
private:
	InputHandler();
	~InputHandler();

	static InputHandler* instance;
};

