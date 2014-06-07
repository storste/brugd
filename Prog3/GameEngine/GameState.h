#pragma once
#include <list>
#include <iostream>
#include "GameObject.h"

// forward declarations
//class GameObject;
class GameEngine;

class GameState {
public:

	GameState() { std::cout << "GameState: Constructor" << std::endl; }

	virtual ~GameState(){}

	virtual void handleEvents() = 0;
	virtual void update(int ticks) = 0;
	virtual void render() = 0;
	virtual void checkTransition() = 0;

	void addGameObject(GameObject* d){
		_objects.push_back(d);
	}

	void removeGameObject(GameObject* d){
		d->set_visible();
	}

	std::list<GameObject*> getObjects(){
		return _objects;
	};

protected:
	GameEngine* _world = nullptr;
	std::list<GameObject*> _objects;
};

