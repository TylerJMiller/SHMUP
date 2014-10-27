#include "AIE.h"
#include "MyMaths.h"
#include "KeyStater.h"
#include <iostream>
#include "Ship.h"
#include <math.h>
#include "Improv.h"

int sWidth = 800;
int sHeight = 600;
int spriteCount = 0;
float frameTime = 0;
KeyStater Keys;
Ship Player1/*, Player2, Player3, Player4*/;

enum GAMESTATE
{
	MAINMENU,
	LOADGAME,
	GAMEPLAY,
	HISCORE,
	QUIT,
	UNLOAD
};

GAMESTATE CurrentState = LOADGAME;

void InitializeGame(), MainMenu(), LoadGame(), GameUpdate(), GameDraw(), HiScore(), QuitGame(), Unload();

int main( int argc, char* argv[] )
{	
    Initialise(sWidth, sHeight, false, "shootmeup");
    SetBackgroundColour(SColour(0, 0, 0, 255));
	
    //Game Loop
    do
    {
		Keys.Update();
		Keys.Debug();
		frameTime = GetDeltaTime();
		if (Keys.IsPressed(VK_ESCAPE))
			CurrentState = UNLOAD;
		switch (CurrentState)
		{
		case MAINMENU:
			MainMenu();
			break;
		case LOADGAME:
			LoadGame();
			break;
		case GAMEPLAY:
			GameUpdate();
			GameDraw();
			break;
		case HISCORE:
			HiScore();
			break;
		case QUIT:
			QuitGame();
			break;
		case UNLOAD:
			Unload();
			return 0;
			break;
		default:
			break;
		}
        ClearScreen();

    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}

void MainMenu()
{

}

void LoadGame()
{
	Player1.SetPos(100, 100, 15);
	Player1.SetSpeed(300, 0, 0);
	Player1.SetSprite(MakeSprite("./images/ship.png", 31, 31, spriteCount));
	Player1.SetKeys(VK_W, VK_S, VK_A, VK_D, VK_SPACE);
	/*
	Player2.SetPos(200, 100, 15);
	Player2.SetSpeed(300, 0, 0);
	Player2.SetSprite(MakeSprite("./images/ship2.png", 31, 31, spriteCount));
	Player2.SetKeys(VK_I, VK_K, VK_J, VK_L, VK_SPACE);

	Player3.SetPos(300, 100, 15);
	Player3.SetSpeed(300, 0, 0);
	Player3.SetSprite(MakeSprite("./images/ship3.png", 31, 31, spriteCount));
	Player3.SetKeys(VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, VK_SPACE);

	Player4.SetPos(400, 100, 15);
	Player4.SetSpeed(300, 0, 0);
	Player4.SetSprite(MakeSprite("./images/ship4.png", 31, 31, spriteCount));
	Player4.SetKeys(VK_NUMPAD8, VK_NUMPAD5, VK_NUMPAD4, VK_NUMPAD6, VK_SPACE);
	*/
	CurrentState = GAMEPLAY;
}

void GameUpdate()
{
	Player1.Update(Keys, sWidth, sHeight);
	/*
	Player2.Update(Keys, sWidth, sHeight);
	Player3.Update(Keys, sWidth, sHeight);
	Player4.Update(Keys, sWidth, sHeight);
	*/

	Player1.Move(frameTime);
	/*
	Player2.Move(frameTime);
	Player3.Move(frameTime);
	Player4.Move(frameTime);
	*/
}

void GameDraw()
{
	Player1.Draw();
	/*
	Player2.Draw();
	Player3.Draw();
	Player4.Draw();
	*/
}

void HiScore()
{

}

void QuitGame()
{

}

void Unload()
{

}