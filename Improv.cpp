#include "Improv.h"
#include "AIE.h"


int MakeSprite(char *atext, int awidth, int aheight, int &asprites)
{
	asprites++;
	return CreateSprite(atext, awidth, aheight, true, SColour(255, 255, 255, 255));
}