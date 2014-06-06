#pragma once
#include "GameObject.h"
#include <vector>

class GameState
{
public:

	virtual ~GameState(){}

	virtual void HandleEvents() = 0;
	virtual void Update(int ticks) = 0;
	virtual void Render() = 0;
	virtual void CheckTransition() = 0;

	virtual void addGameObject(GameObject* d) = 0;
	virtual void removeGameObject(GameObject* d) = 0;
	virtual std::vector<GameObject*> getObjects() = 0;
};

