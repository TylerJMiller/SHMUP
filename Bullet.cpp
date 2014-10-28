#include "Bullet.h"


void Bullet::Update(float aWidth, float aHeight)
{
	if (active)
	{
		if ((y + 50) > aHeight)
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
