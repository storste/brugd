#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"

class StateIntro :
	public GameState
{
public:
	StateIntro();
	~StateIntro();

	virtual void HandleEvents();
	virtual void Update(int ticks);
	virtual void Render();
	virtual void CheckTransition();

	std::vector<GameObject*> objects;
	virtual void addGameObject(GameObject* d){
		objects.push_back(d);
	}

	virtual void removeGameObject(GameObject* d){
		d->set_visible();
	}

	virtual std::vector<GameObject*> getObjects(){ return objects; };
};

