#ifndef SHIP_H
#define SHIP_H
#include "Object.h"
#include "KeyStater.h"
#include "MyMaths.h"
class Ship : public Object
{
private:
	int bUp, bDown, bLeft, bRight, bFire, bType;
public:
	void Shoot();
	void SetKeys(int aUp, int aDown, int aLeft, int aRight, int aFire);
	void Update(KeyStater &aKeys, float aWidth, float aHeight);
	Ship();
	~Ship();

};

#endif