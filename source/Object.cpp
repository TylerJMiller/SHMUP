#include "Object.h"
#include "MyMaths.h"
#include "AIE.h"
#include "KeyStater.h"

Object::Object()
{
	active = false;
}

void Object::SetPos(float ax, float ay, float ar)
{
	x = ax;
	y = ay;
	r = ar;
}

void Object::SetSpeed(float as, float axdir, float aydir)
{
	speed = as;
	dir.x = axdir;
	dir.y = aydir;
}
void Object::SetSprite(int asprite)
{
	spriteID = asprite;
}

void Object::Move(float atime)
{
	if (active)
	{
		x += dir.x * speed * atime;
		y += dir.y * speed * atime;
	}
	MoveSprite(spriteID, x, y);
}

Point2D Object::ForwardMove()
{
	return Point2D(x + dir.x * speed * GetDeltaTime(), y + dir.y * speed * GetDeltaTime());
}

void Object::Draw()
{
	if (active)
	{
		DrawSprite(spriteID);
	}
}

Object::~Object()
{
}