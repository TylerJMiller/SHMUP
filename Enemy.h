#ifndef ENEMY_H
#define ENEMY_H
#include "Object.h"
class Enemy : public Object
{
public:
	void Update(float aWidth, float aHeight);
	Enemy();
	~Enemy();
};

#endif