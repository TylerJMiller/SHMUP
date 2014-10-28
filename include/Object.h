#ifndef OBJECT_H
#define OBJECT_H
#include "MyMaths.h"

class Object
{
public:
	float x, y, r;
	int spriteID;
	float speed;
	bool active;
	Vector2D dir;

	void SetPos(float ax, float ay, float ar);
	void SetSpeed(float as, float axdir, float aydir);
	void SetSprite(int asprite);
	void Move(float atime);
	Point2D ForwardMove();	//RETURNS POSITION NEXT FRAME
	void Draw();
	Object();
	~Object();
};
#endif