#ifndef IMPROV_H
#define IMPROV_H
																			//SPAGHETTI BOX
#include "AIE.h"
#include "MyMaths.h"
#include "KeyStater.h"
#include <iostream>
#include "Ship.h"
#include <math.h>

enum GAMESTATE
{
	MAINMENU,
	LOADGAME,
	GAMEPLAY,
	HISCORE,
	QUIT,
	UNLOAD
};

struct GameStateHandler
{
	GAMESTATE CurrentState, LastState;

	bool hasChanged = false;

	GameStateHandler(GAMESTATE aState)
	{
		CurrentState = aState;
		LastState = CurrentState;
	}

	void ChangeState(GAMESTATE aState)
	{
		hasChanged = true;
		LastState = CurrentState;
		CurrentState = aState;
	}

	void Update()
	{
		hasChanged = false;
	}
};

GameStateHandler Game(MAINMENU);

int sWidth = 800;
int sHeight = 600;
int spriteCount = 0;
float frameTime = 0, totalTime = 0;
KeyStater Keys;
Ship Player1/*, Player2, Player3, Player4*/;




void InitializeGame(), MainMenu(), LoadGame(), GamePlay(), GameDraw(), HiScore(), Quit(), Unload();


int MakeSprite(char *atext, int awidth, int aheight, int &asprites)
{
	asprites++;
	return CreateSprite(atext, awidth, aheight, true, SColour(255, 255, 255, 255));
}

#endif