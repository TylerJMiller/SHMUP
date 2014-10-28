#include "Ship.h"

Ship::Ship()
{
	active = true;
}
void Ship::SetKeys(int aUp, int aDown, int aLeft, int aRight, int aFire)
{
	bUp = aUp;
	bDown = aDown;
	bLeft = aLeft;
	bRight = aRight;
	bFire = aFire;
}

void Ship::Update(KeyStater &aKeys, float aWidth, float aHeight)
{
	if (aKeys.IsPressed(bUp))
		dir.y = 1;
	if (aKeys.IsPressed(bDown))
		dir.y = -1;
	if (aKeys.IsPressed(bLeft))
		dir.x = -1;
	if (aKeys.IsPressed(bRight))
		dir.x = 1;
	if (aKeys.IsReleased(bUp) && aKeys.IsDown(bDown))
		dir.y = -1;
	if (aKeys.IsReleased(bDown) && aKeys.IsDown(bUp))
		dir.y = 1;
	if (aKeys.IsReleased(bRight) && aKeys.IsDown(bLeft))
		dir.x = -1;
	if (aKeys.IsReleased(bLeft) && aKeys.IsDown(bRight))
		dir.x = 1;
	if (aKeys.IsUp(bUp) && aKeys.IsUp(bDown))
		dir.y = 0;
	if (aKeys.IsUp(bLeft) && aKeys.IsUp(bRight))
		dir.x = 0;
	if (!CheckPointBox(ForwardMove(), Box(0, (0.1 * aHeight), aWidth, (0.6 * aHeight))))
	{
		dir.y = 0;
	}
	if (!CheckPointBox(ForwardMove(), Box((0.05 * aWidth), 0, (0.95 * aWidth), aHeight)))
	{
		dir.x = 0;
	}





}

Ship::~Ship()
{
}