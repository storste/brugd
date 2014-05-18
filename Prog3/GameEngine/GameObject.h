#pragma once
#include <string>

class GameObject {
public:
	GameObject();
	~GameObject();
	virtual void render();
	virtual void update(int dt);
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getW() = 0;
	virtual int getH() = 0;
	virtual std::string getName() = 0;
};

