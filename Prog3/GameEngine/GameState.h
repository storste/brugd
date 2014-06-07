#pragma once
#include <list>
#include <iostream>
#include "GameObject.h"
//#include "GameEngine.h"

// forward declarations
//class GameObject;
class GameEngine;

class GameState {
public:

	GameState()  {
		std::cout << "GameState: Constructor" << std::endl;
		//_world = GameEngine::getInstance();
	} 

	virtual ~GameState(){}

	virtual void update(int ticks)
	{
		for (const auto& o : m_objects){
			o->update(ticks);
		}
	}

	virtual void checkTransition() = 0;

	void addGameObject(GameObject* d){
		m_objects.push_back(d);
	}

	void removeGameObject(GameObject* d){
		d->set_visible();
	}

	std::list<GameObject*> getObjects(){
		return m_objects;
	};

protected:
	GameEngine* m_world = nullptr;
	std::list<GameObject*> m_objects;
};

