#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Animation.h"
#include <string>
#include <map>

class Sprite :public GameObject {
public:
	Sprite(const char* filename, SDL_Renderer* r);
	Sprite(Animation* a);
	Sprite();
	~Sprite();
	virtual void render();
	virtual void setPosition(int x, int y);
	int getY();
	int getX();
	int getH();
	int getW();
	void setName(const char *name);
	std::string getName();
	virtual std::string getName() const{ return m_name; }
	virtual void update(int dt);

	void addAnimation(std::string name, Animation* a);
	void setAnimation(const char *name);
	Animation* getAnimation();

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	int width;
	int height;
	int x;
	int y;
	std::string m_name;
	std::map<std::string, Animation*> animations;
	Animation* currentAnimation;
};

