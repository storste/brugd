#pragma once
#include "SDL.h"

class InputHandler
{
public:
	void update();
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
private:
	InputHandler();
	~InputHandler();

	static InputHandler* s_pInstance;
};

