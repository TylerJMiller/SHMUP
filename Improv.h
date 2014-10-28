#ifndef IMPROV_H
#define IMPROV_H
																			//SPAGHETTI BOX
#include "AIE.h"
#include "MyMaths.h"
#include "KeyStater.h"
#include <iostream>
#include "Ship.h"
#include <math.h>
#include "Enemy.h"
#include "Bullet.h"

enum GAMESTATE
{
	MAINMENU,
	LOADGAME,
	GAMEPLAY,
	HISCORE,
	QUIT,
	UNLOAD
};

float frameTime = 0, totalTime = 0;

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
		totalTime = 0;
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

bool pause = false;
int sWidth = 800;
int sHeight = 600;
int spriteCount = 0;

const int slaserCount = 500;
int fireTime = 0;

const int alienCount = 5;

KeyStater Keys;
Ship Player1;
Bullet SLaser[slaserCount];
Enemy Alien[alienCount];
/*
Ship Player2;
Ship Player3;
Ship Player4;
*/

void AlienPlayerCollision()
{
	for (int i = 0; i < alienCount; i++)
	{
		if (CheckCircleCircle(Player1.x, Player1.y, Player1.r, Alien[i].x, Alien[i].y, Alien[i].r))															//FIX THIS SHIT
		{
			Alien[i].active = false;
		}
	}
}


bool AlienActiveCheck()
{
	int a = alienCount;
	for (int i = 0; i < alienCount; i++)
	{
		if (!Alien[i].active)
			a--;
	}
	if (a == 0)
		return false;
	return true;
}

void BREAK()
{
	sWidth = sWidth;
}

void InitializeGame(), MainMenu(), LoadGame(), GamePlay(), GameDraw(), HiScore(), Quit(), Unload();

int MakeSprite(char *atext, int awidth, int aheight, int &asprites)
{
	asprites++;
	return CreateSprite(atext, awidth, aheight, true, SColour(255, 255, 255, 255));
}

int GetNextBullet()
{
	for (int i = 0; i < slaserCount; i++)
	{
		if (!SLaser[i].active)
			return i;
	}
	return -1;
}

void Shoot()
{
	if (fireTime > 0)
		fireTime -= frameTime;
	if ((Keys.IsPressed(VK_SPACE) || Keys.IsDown(VK_SPACE)) && fireTime == 0)
	{
		fireTime = 0.2; 
		SLaser[GetNextBullet()].x = Player1.x;
		SLaser[GetNextBullet()].y = Player1.y;
		SLaser[GetNextBullet()].active = true;
	}
}

void AlienSLaserCollision()
{
	for (int i = 0; i < slaserCount; i++)
	{
		if (SLaser[i].active)
		{
			for (int ii = 0; ii < alienCount; ii++)
			{
				if (Alien[ii].active)
				{
					if (CheckCircleCircle(Alien[ii].x, Alien[ii].y, Alien[ii].r, SLaser[i].x, SLaser[i].y, SLaser[i].r))
						Alien[ii].active = false;
				}
			}
		}
	}
}

#endif