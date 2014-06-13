#ifndef SCORESPRITE_H
#define SCORESPRITE_H

#include "../../GameEngine/Sprite.h"

class ScoreSprite :
	public Sprite {
public:
	ScoreSprite();
	void render();
};

#endif