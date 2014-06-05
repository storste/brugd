#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Animation.h"
#include <string>
#include <map>

class Sprite :public GameObject {

public:

	Sprite(const char* filename);
	Sprite(Animation* a);
	Sprite();
	~Sprite();

	virtual void render();

	virtual void setPosition(int x, int y);
	virtual int getY();
	virtual int getX();
	virtual int getH();
	virtual int getW();

	virtual void setName(const char *name);

	virtual const std::string getName();
	virtual void update(int dt);

	void addAnimation(std::string name, Animation* a);
	void setAnimation(const char *name);
	Animation* getAnimation();
	bool is_visible(){ return _is_visible; }
	void set_visible() { _is_visible = false; }

private:
	SDL_Texture* texture;

	std::string m_name;
	std::map<std::string, Animation*> animations;
	Animation* currentAnimation;
	int w;
	int h;
	int x;
	int y;
	bool _is_visible;

protected:
};

