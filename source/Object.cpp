#include "Object.h"
#include "MyMaths.h"
#include "AIE.h"
#include "KeyStater.h"

Object::Object()
{
	active = false;
}

void Object::SetPos(float ax, float ay, float ar)		//POSITION AND RADIUS SETTER
{
	x = ax;
	y = ay;
	r = ar;
}

void Object::SetSpeed(float as, float axdir, float aydir)		//POSITION AND RADIUS SETTER
{
	speed = as;
	dir.x = axdir;
	dir.y = aydir;
}
void Object::SetSprite(int asprite)		//SPRITE SETTER
{
	spriteID = asprite;
}

void Object::Move(float atime)		//MOVE FUNCTION - CALL EVERY FRAME
{
	if (active)
	{
		x += dir.x * speed * atime;
		y += dir.y * speed * atime;
	}
	MoveSprite(spriteID, x, y);
}

Point2D Object::ForwardMove()	//RETURNS POSITION NEXT FRAME
{
	return Point2D(x + dir.x * speed * GetDeltaTime(), y + dir.y * speed * GetDeltaTime());
}

void Object::Draw()		//DRAW FUNCITON
{
	if (active)
	{
		DrawSprite(spriteID);
	}
}

Object::~Object()
{
}