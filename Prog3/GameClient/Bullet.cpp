#include "Bullet.h"


Bullet::Bullet(const char* filename, MovementDirection dir, int velocity) : MovingObject(filename, dir, velocity)
{
}


Bullet::~Bullet()
{
}

void Bullet::update(int dt)
{
	MovingObject::update();
}