#ifndef OBJECT_H
#define OBJECT_H
#include "MyMaths.h"

//GENERIC OBJECT CLASS

class Object
{
public:
	float x, y, r;
	int spriteID;
	float speed;
	bool active;
	Vector2D dir;

	void SetPos(float ax, float ay, float ar);	//POSITION AND RADIUS SETTER
	void SetSpeed(float as, float axdir, float aydir);	//SPEED SETTER
	void SetSprite(int asprite);	//SPRITE SETTER
	void Move(float atime);	//MOVEMENT FUNCITON
	Point2D ForwardMove();	//RETURNS POSITION NEXT FRAME
	void Draw();	//DRAW FUNCTION
	Object();
	~Object();
};
#endif