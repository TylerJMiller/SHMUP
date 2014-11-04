#include "Bullet.h"


void Bullet::Update(float aWidth, float aHeight)
{
	if (active)
	{
		if (y > aHeight + 50)	//GOES INACTIVE IF OFF SCREEN
			active = false;		
	}
}

Bullet::Bullet()
{
	active = false;		//STARTS INACTIVE
}


Bullet::~Bullet()
{
}
