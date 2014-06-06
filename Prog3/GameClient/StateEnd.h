#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"

class StateEnd :
	public GameState {
public:
	StateEnd();
	~StateEnd();
	virtual void HandleEvents();
	virtual void Update(int ticks);
	virtual void Render();
	virtual void CheckTransition();

	void RenderScore();

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

