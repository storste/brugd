#pragma once
#include "..\GameEngine\GameState.h"

// forward declaration
class GameObject;

class StateIntro :
	public GameState {
public:
	StateIntro();
	~StateIntro();

	void HandleEvents() override;
	void Update(int ticks) override;
	void Render() override;
	void CheckTransition() override;

	void addGameObject(GameObject* d) override;
	void removeGameObject(GameObject* d) override;
	std::list<GameObject*> getObjects() override;

private:
	std::list<GameObject*> objects;

};

