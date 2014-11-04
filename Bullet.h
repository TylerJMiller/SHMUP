#ifndef BULLET_H
#define BULLET_H
#include "Object.h"
class Bullet : public Object
{
public:
	void Update(float aWidth, float aHeight);	//BULLET UPDATE
	Bullet();
	~Bullet();
};

#endif