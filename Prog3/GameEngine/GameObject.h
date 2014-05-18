#pragma once
#include <string>

class GameObject {
public:
	GameObject();
	~GameObject();
	virtual void render();
	virtual void update();
	virtual std::string getName() = 0;
};

