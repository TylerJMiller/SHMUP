#include "Improv.h"

int main( int argc, char* argv[] )
{	
    Initialise(sWidth, sHeight, false, "shootmeup");
    SetBackgroundColour(SColour(0, 0, 0, 255));
	totalTime += frameTime;
    //Game Loop
    do
    {
		Game.Update();
		Keys.Update();
		Keys.Debug();
		frameTime = GetDeltaTime();
		if (Keys.IsPressed(VK_ESCAPE))
			Game.ChangeState(UNLOAD);
		switch (Game.CurrentState)
		{
		case MAINMENU:
			MainMenu();
			break;
		case LOADGAME:
			LoadGame();
			break;
		case GAMEPLAY:
			GamePlay();
			GameDraw();
			break;
		case HISCORE:
			HiScore();
			break;
		case QUIT:
			Quit();
			break;
		case UNLOAD:
			Unload();
			return 0;
			break;
		default:
			Game.ChangeState(UNLOAD);
				break;
	}
        ClearScreen();
    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}

void MainMenu()
{
	Game.ChangeState(LOADGAME);
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
	Game.ChangeState(GAMEPLAY);
}

void GamePlay()
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

void Quit()
{

}

void Unload()
{

}