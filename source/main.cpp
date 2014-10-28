#include "Improv.h"

int main( int argc, char* argv[] )
{	
    Initialise(sWidth, sHeight, false, "shootmeup");
    SetBackgroundColour(SColour(0, 0, 0, 255));
    //Game Loop
    do
    {
		Game.Update();
		Keys.Update();
		Keys.Debug();
		frameTime = GetDeltaTime();
		//frameTime = 1/60;
		totalTime += frameTime;
		if (Keys.IsPressed(VK_ESCAPE))
			Game.ChangeState(UNLOAD);

		if (Keys.IsPressed(VK_P))
			pause = !pause;

		if (Keys.IsPressed(VK_TAB))
			BREAK();

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
	if (Keys.IsPressed(VK_RETURN))
		totalTime = 5;
	if (totalTime < 5)
	{
		DrawString("VIDEO GAME SPLASH SCREEN", 0.25f * sWidth, 0.5f * sHeight, SColour(255, 255, 255, 255));
	}
	else
	{
		Game.ChangeState(LOADGAME);
	}
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
	Player4.SetPos(0.8f * sWidth, 100, 15);
	Player4.SetSpeed(300, 0, 0);
	Player4.SetSprite(MakeSprite("./images/ship4.png", 31, 31, spriteCount));
	Player4.SetKeys(VK_NUMPAD8, VK_NUMPAD5, VK_NUMPAD4, VK_NUMPAD6, VK_SPACE);
*/
	
	for (int i = 0; i < alienCount; i++)
	{
		Alien[i].SetPos((i + 3) * 0.1f * sWidth, 0.9f * sHeight, 15);
		Alien[i].SetSpeed(100, 0, -1);
		Alien[i].SetSprite(MakeSprite("./images/alien.png", 31, 31, spriteCount));
	}

	for (int i = 0; i < slaserCount; i++)
	{
		SLaser[i].SetPos(-100, -100, 6);
		SLaser[i].SetSpeed(600, 0, 1);
		SLaser[i].SetSprite(MakeSprite("./images/slaser.png", 4, 12, spriteCount));
	}

	Game.ChangeState(GAMEPLAY);
}

void GamePlay()
{
	if (!pause)
	{
		Player1.Update(Keys, sWidth, sHeight);		//PLAYER UPDATE
		/*
		Player2.Update(Keys, sWidth, sHeight);
		Player3.Update(Keys, sWidth, sHeight);
		Player4.Update(Keys, sWidth, sHeight);
		*/

		for (int i = 0; i < alienCount; i++)
		{
			Alien[i].Update(sWidth, sHeight);		//ALIEN ARRAY UPDATE
		}

		for (int i = 0; i < slaserCount; i++)
		{
			SLaser[i].Update(sWidth, sHeight);
		}

		Shoot();
		AlienSLaserCollision();
		AlienPlayerCollision();
		if (!AlienActiveCheck())
			Game.ChangeState(UNLOAD);

		Player1.Move(frameTime);					//PLAYER MOVE
		/*
		Player2.Move(frameTime);
		Player3.Move(frameTime);
		Player4.Move(frameTime);
		*/

		for (int i = 0; i < slaserCount; i++)
		{
			SLaser[i].Move(frameTime);
		}

		for (int i = 0; i < alienCount; i++)
		{
			Alien[i].Move(frameTime);				//PLAYER MOVE
		}
	}
}

void GameDraw()
{
	Player1.Draw();								//PLAYER DRAW
	/*
	Player2.Draw();
	Player3.Draw();
	Player4.Draw();
	*/
	for (int i = 0; i < alienCount; i++)
	{	
		Alien[i].Draw();						//ALIEN ARRAY DRAW
	}
	for (int i = 0; i < slaserCount; i++)
	{
		SLaser[i].Draw();
	}
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