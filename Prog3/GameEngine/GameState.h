#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <list>
#include <map>
#include <functional>
#include <iostream>
#include "GameObject.h"
#include <SDL.h>

// forward declarations
class GameEngine;

class GameState {
public:

	GameState();
	virtual ~GameState();

	virtual void update(int ticks);
	virtual void checkTransition() = 0;

	void addGameObject(GameObject* d);
	void removeGameObject(GameObject* d);
	std::list<GameObject*> getObjects();

	// hur ska funktionen se ut egentligen?????
	//void addKeyFunction(SDL_Scancode key, std::function<void()> func, GameObject* obj){
	//	//std::pair<SDL_Scancode, void (GameObject::*)()> pair = std::make_pair(SDL_SCANCODE_SPACE, func);
	//	m_keymap[key] = std::bind(&func, &obj);
	//	//m_keymap.insert(pair);
	//}

	void invokeFuncForKey(SDL_Scancode key);

	std::map<SDL_Scancode, std::function<void()>>& getKeyMap();

	int getLevel();
	void setLevel(int lvl);
	void increaseLevel();

protected:
	GameEngine* m_world = nullptr;
	std::list<GameObject*> m_objects;

	std::map<SDL_Scancode, std::function<void()>> m_keymap;

	bool deleteState = false;

private:
	int m_level = 0;
};


#endif