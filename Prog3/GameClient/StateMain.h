#pragma once
#include "..\GameEngine\GameState.h"
#include "..\GameEngine\GameEngine.h"
#include <iostream>

class StateMain :
	public GameState {
public:
	StateMain();
	~StateMain();
	void HandleEvents();
	void Update(int ticks);
	void Render();
	void CheckTransition();

	void addGameObject(GameObject* d){
		objects.push_back(d);
	}

	void removeGameObject(GameObject* d){
		d->set_visible();
	}

	std::list<GameObject*> getObjects(){ return objects; };
	
	void StateMain::RenderScore();

private:
	std::list<GameObject*> objects;
};

