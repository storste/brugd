#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"

class StatePause :
	public GameState {
public:
	StatePause();
	~StatePause();
	virtual void HandleEvents();
	virtual void Update(int ticks);
	virtual void Render();
	virtual void CheckTransition();

	

	virtual void addGameObject(GameObject* d){
		objects.push_back(d);
	}

	virtual void removeGameObject(GameObject* d){
		d->set_visible();
	}

	virtual std::list<GameObject*> getObjects(){ return objects; };

private:
	std::list<GameObject*> objects;
};

