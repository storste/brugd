#pragma once
#include "GameObject.h"
#include <vector>

class GameState
{
public:

	virtual ~GameState(){}

	virtual void handleEvents() = 0;
	virtual void update(int ticks) = 0;
	virtual void render() = 0;

	virtual void addGameObject(GameObject* d) = 0;
	virtual void removeGameObject(GameObject* d) = 0;
	virtual std::vector<GameObject*> getObjects() = 0;


};

