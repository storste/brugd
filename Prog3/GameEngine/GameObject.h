#pragma once
#include <string>

class GameObject {
public:
	GameObject();
	~GameObject();
	virtual void render() = 0;
	virtual void update(int dt) = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getW() = 0;
	virtual int getH() = 0;
	virtual const std::string getName() = 0;
	virtual bool is_visible() = 0;
	virtual void set_visible() = 0;
};

