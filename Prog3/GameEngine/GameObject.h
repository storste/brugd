#pragma once

class GameObject {
public:
	GameObject();
	~GameObject();
	virtual void render();
	virtual void update();
};

