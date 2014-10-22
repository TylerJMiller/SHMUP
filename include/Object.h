#ifndef OBJECT_H
#define OBJECT_H
#include "MyMaths.h"

class Object
{
public:
	float x;
	float y;
	int spriteID;
	float speed;
	bool active;
	Vector2D dir;
	Circle collision;

	void SetPos(float ax, float ay, float ar);
	void SetSpeed(float as, float axdir, float aydir);
	void SetSprite(int asprite);
	void Move(float atime);
	Point2D ForwardMove();
	void Draw();
	Object();
	~Object();
};
#endif