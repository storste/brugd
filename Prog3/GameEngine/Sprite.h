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
	virtual void setName(std::string name){ m_name = name; }
	std::string getName(){ return m_name; }
	virtual std::string getName() const{ return m_name; }
	virtual void update(int dt);
	void addAnimation(std::string name, Animation* a){
		std::pair<std::string, Animation*> pair = std::make_pair(name, a);
		animations.insert(pair);
	}
	void setAnimation(const char* name){

		currentAnimation = animations[name];
	}
	Animation* getAnimation(){ return currentAnimation; }

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

