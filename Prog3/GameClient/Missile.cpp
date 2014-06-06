#include "Missile.h"
#include <iostream>

Missile::Missile(const char* filename, const char* name) :Sprite(filename)
{
	printf("Creating missile\n");
}

Missile::~Missile()
{
	std::cout << "Missile: Destructor" << std::endl;
}
