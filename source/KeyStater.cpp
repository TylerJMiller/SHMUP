#include "KeyStater.h"
#include <Windows.h>

KeyStater::KeyStater()
{
	//INITILIZES CURRENT AND LAST KEYBOARD STATE ON DECLARATION
	GetKeyboardState(curStates);
	for (int i = 0; i < 256; i++)
	{
		oldStates[i] = curStates[i];	
	}
	GetCursorPos(&curs);	//CURSOR POSITION ON SCREEN
	ScreenToClient(thiswindow, &curs);	//CURSOR POSITION IN RELATION TO GAME WINDOW
}


KeyStater::~KeyStater()
{
}

void KeyStater::Update()	//REFRESHING KEYSTATES AND MOUSE POSITION
{
	for (int i = 0; i < 256; i++)
	{
		oldStates[i] = curStates[i];
	}
	GetKeyboardState(curStates);
	GetCursorPos(&curs);
	ScreenToClient(thiswindow, &curs);
}
void KeyStater::Debug()		//DRAWS CURSTATE ON SCREEN IF F5 IS TOGGLED
{
	if (IsPressed(VK_F5))
		showDebug = !showDebug;

	if (showDebug)
	{
		for (int i = 0; i < 16; i++)
		{
			for (int a = 0; a < 16; a++)
			{
				char keyhold[10];
				_itoa_s(curStates[(i * 16) + a], keyhold, 10);
				DrawString(keyhold, i * 20, (a * 20) + 40, SColour(125, 125, 125, 255));
			}
		}
	}
}

bool KeyStater::IsUp(int key)	//IF A KEY IS NEUTRAL
{
	if (curStates[key] < 2 && oldStates[key] < 2)
		return true;
	return false;
}
bool KeyStater::IsDown(int key)	//IF A KEY IS HELD DOWN
{
	if (curStates[key] > 2 && oldStates[key] > 2)
		return true;
	return false;
}
bool KeyStater::IsToggledOn(int key)	//IF A KEY IS TOGGLED
{
	if (curStates[key] == 1)
		return true;
	return false;
}
bool KeyStater::IsPressed(int key)	//IF A KEY HAS BEEN PRESSED SINCE LAST FRAME
{
	if (curStates[key] > 2 && oldStates[key] < 2)
		return true;
	return false;
}
bool KeyStater::IsReleased(int key)	//IF A KEY HAS BEEN RELEASED SINCE LAST FRAME
{
	if (curStates[key] < 2 && oldStates[key] > 2)
		return true;
	return false;
}