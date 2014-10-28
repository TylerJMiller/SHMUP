#include "Enemy.h"


void Enemy::Update(float aWidth, float aHeight)
{
	if (active)
	{
		if (y < -50)
		{
			y = aHeight + 49;
		}
	}
}

Enemy::Enemy()
{
	active = true;
}


Enemy::~Enemy()
{
}
