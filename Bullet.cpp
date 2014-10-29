#include "Bullet.h"


void Bullet::Update(float aWidth, float aHeight)
{
	if (active)
	{
		if (y > aHeight + 50)
			active = false;
	}
}

Bullet::Bullet()
{
	active = false;
}


Bullet::~Bullet()
{
}
