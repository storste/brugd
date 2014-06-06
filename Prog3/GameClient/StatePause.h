#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"

class StatePause :
	public GameState {
public:
	StatePause();
	~StatePause();
	virtual void handleEvents();
	virtual void update(int ticks);
	virtual void render();

	std::vector<GameObject*> objects;
	virtual void addGameObject(GameObject* d){
		objects.push_back(d);
	}

	virtual void removeGameObject(GameObject* d){
		d->set_visible();
	}
	virtual std::vector<GameObject*> getObjects(){ return objects; };

};

