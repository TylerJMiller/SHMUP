#include "Improv.h"

int main( int argc, char* argv[] )
{	

	//INITILIZE FRAMEWORK
    Initialise(sWidth, sHeight, false, "shootmeup");
    SetBackgroundColour(SColour(0, 0, 0, 255));
    //Game Loop
    do
    {
		//UPDATING GAMESTATE AND KEYSTATE
		Game.Update();
		Keys.Update();

		//KEYSTATE DEBUG
		Keys.Debug();
		
		//TIME SINCE LAST FRAME AND TIME SINCE LAST STATE CHANGE
		frameTime = GetDeltaTime();
		//frameTime = (1.f/300);
		totalTime += frameTime;
		
		//DEBUG COMMANDS
		if (Keys.IsPressed(VK_ESCAPE))
			Game.ChangeState(UNLOAD);
		if (Keys.IsPressed(VK_P))
			pause = !pause;
		if (Keys.IsPressed(VK_TAB))
			BREAK();

		//GAMESTATE SWITCH
		switch (Game.CurrentState)
		{
		case SPLASHSCREEN:
			SplashScreen();
			break;
		case MAINMENU:
			MainMenu();
			break;
		case LOADGAME:
			LoadGame();
			break;
		case RELOADGAME:
			ReloadGame();
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

void SplashScreen()		//SPLASH SCREEN
{
	if (Keys.IsPressed(VK_RETURN))	//PRESS ENTER TO SKIP SPLASH SCREEN
		totalTime = 5;
	if (totalTime < 5)
	{
		DrawString("VIDEO GAME SPLASH SCREEN", 0.25f * sWidth, 0.5f * sHeight, SColour(255, 255, 255, 255));
	}
	else
	{
		Game.ChangeState(MAINMENU);
	}
}

void MainMenu()		//MAIN MENU
{
	DrawString("PRESS F TO PLAY", 0.25f * sWidth, 0.7f * sHeight, SColour(255, 255, 255, 255));
	if (Keys.IsPressed(VK_F))
	{
		if (Game.LastState == SPLASHSCREEN)
			Game.ChangeState(LOADGAME);
		else
			Game.ChangeState(RELOADGAME);
	}
	DrawString("PRESS G TO HISCORES", 0.25f * sWidth, 0.5f * sHeight, SColour(255, 255, 255, 255));
	if (Keys.IsPressed(VK_G))
		Game.ChangeState(HISCORE);

	DrawString("PRESS H TO QUIT", 0.25f * sWidth, 0.3f * sHeight, SColour(255, 255, 255, 255));
	if (Keys.IsPressed(VK_H))
		Game.ChangeState(QUIT);
}

void LoadGame()		//LOAD GAME FOR THE FIRST TIME
{
	newHi = false;
	Player1.active = true;
	Player1.SetPos(100, 100, 15);
	Player1.SetSpeed(300, 0, 0);
	Player1.SetSprite(MakeSprite("./images/ship.png", 31, 31, spriteCount));
	Player1.SetKeys(VK_W, VK_S, VK_A, VK_D, VK_SPACE);
	/*
	Player2.active = true;
	Player2.SetPos(200, 100, 15);
	Player2.SetSpeed(300, 0, 0);
	Player2.SetSprite(MakeSprite("./images/ship2.png", 31, 31, spriteCount));
	Player2.SetKeys(VK_I, VK_K, VK_J, VK_L, VK_SPACE);

	Player3.active = true;
	Player3.SetPos(300, 100, 15);
	Player3.SetSpeed(300, 0, 0);
	Player3.SetSprite(MakeSprite("./images/ship3.png", 31, 31, spriteCount));
	Player3.SetKeys(VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, VK_SPACE);

	Player4.active = true;
	Player4.SetPos(0.8f * sWidth, 100, 15);
	Player4.SetSpeed(300, 0, 0);
	Player4.SetSprite(MakeSprite("./images/ship4.png", 31, 31, spriteCount));
	Player4.SetKeys(VK_NUMPAD8, VK_NUMPAD5, VK_NUMPAD4, VK_NUMPAD6, VK_SPACE);
	*/

	
	for (int i = 0; i < alienCount; i++)
	{
		Alien[i].active = true;
		Alien[i].SetPos((i + 3) * 0.1f * sWidth, 0.9f * sHeight, 15);
		Alien[i].SetSpeed(100, 0, -1);
		Alien[i].SetSprite(MakeSprite("./images/alien.png", 31, 31, spriteCount));
	}
	for (int i = 0; i < splasmaCount; i++)
	{
		SPlasma[i].active = false;
		SPlasma[i].SetPos(-100, -100, 6);
		SPlasma[i].SetSpeed(600, 0, 1);
		SPlasma[i].SetSprite(MakeSprite("./images/splasma.png", 4, 12, spriteCount));
	}
	Game.ChangeState(GAMEPLAY);
}

void ReloadGame()		//RESET GAME STATE IF PLAYED ALREADY
{
	alienMark = alienCount;
	s1Lives = 3;
	/*
	s2Lives = 3;
	s3Lives = 3;
	s4Lives = 3;
	*/

	newHi = false;
	Player1.SetPos(100, 100, 15);

	for (int i = 0; i < alienCount; i++)
	{
		Alien[i].active = true;
		Alien[i].SetPos((i + 3) * 0.1f * sWidth, 0.9f * sHeight, 15);
	}

	for (int i = 0; i < splasmaCount; i++)
	{
		SPlasma[i].active = false;
		SPlasma[i].SetPos(-100, -100, 6);
	}
	Game.ChangeState(GAMEPLAY);
}

void GamePlay()		//GAME LOGIC FUNCTION
{
	if (alienMark == 0)		//IF THERE ARE ANY ALIENS LEFT - WIN/LOSE LOGIC OR 
	{
		//WIN LOGIC
		if (totalTime < 10)		
		{
			DrawNum(10 - totalTime, 0.5f, 0.5f);
			DrawString("YOU ARE WINNER", 0.25f * sWidth, 0.8f * sHeight, SColour(255, 255, 255, 255));
			if (newHi)
			{
				DrawString("New HiScore is ", 0.245f * sWidth, 0.7f * sHeight, SColour(255, 255, 255, 255));
				DrawScore(0.495f, 0.7f);
			}
			DrawString("Press F to MAINMENU", 0.25f * sWidth, 0.6f * sHeight, SColour(255, 255, 255, 255));
			if (Keys.IsPressed(VK_F))
				Game.ChangeState(MAINMENU);
			//DrawString("DEBUG", 0.25f * sWidth, 0.8f * sHeight, SColour(255, 255, 255, 255));
		}
		else
		{
			Game.ChangeState(QUIT);
		}
	}
	else if (s1Lives == 0)
	{
		//LOSE LOGIC
		if (totalTime < 10)
		{
			DrawString("YOU ARE LOSE", 0.25f * sWidth, 0.7f * sHeight, SColour(255, 255, 255, 255));
			DrawString("Press F to MAINMENU", 0.25f * sWidth, 0.6f * sHeight, SColour(255, 255, 255, 255));
			DrawNum(10 - totalTime, 0.5f, 0.5f);
			if (Keys.IsPressed(VK_F))
				Game.ChangeState(MAINMENU);
		}
		else
		{
			Game.ChangeState(QUIT);
		}
	}
	else if (!pause)
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

		for (int i = 0; i < splasmaCount; i++)
		{
			SPlasma[i].Update(sWidth, sHeight);
		}

		Shoot();
		AlienSPlasmaCollision();
		AlienPlayerCollision();
		//if (!AlienActiveCheck())
			//Game.ChangeState(UNLOAD);

		Player1.Move(frameTime);					//PLAYER MOVE
		/*
		Player2.Move(frameTime);
		Player3.Move(frameTime);
		Player4.Move(frameTime);
		*/

		for (int i = 0; i < splasmaCount; i++)
		{
			SPlasma[i].Move(frameTime);
		}

		for (int i = 0; i < alienCount; i++)
		{
			Alien[i].Move(frameTime);				//PLAYER MOVE
		}
	}
}

void GameDraw()		//GAME DRAW STATE
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
	for (int i = 0; i < splasmaCount; i++)
	{
		SPlasma[i].Draw();
	}
	DrawUI();
	if (AlienActiveCheck())
		DrawNum(totalTime, 0.8f, 0.9f);
}

void HiScore()		//HI SCORE LOGIC
{
	DrawString("The current HiScore is ", 0.245f * sWidth, 0.5f * sHeight, SColour(255, 255, 255, 255));
	DrawScore(0.6f, 0.5f);
	DrawString("Press G to return", 0.4f * sWidth, 0.3f * sHeight, SColour(255, 255, 255, 255));
	if (Keys.IsPressed(VK_G))
		Game.ChangeState(MAINMENU);
}

void Quit()		//QUIT GAME LOGIC
{
	if (Game.LastState == MAINMENU)
	{
		DrawChar("Quitting from MAINMENU", 0.3f, 0.6f);
		DrawNum(5 - totalTime, 0.5f, 0.5f);
		if (totalTime > 5)
			Game.ChangeState(UNLOAD);
	}
	else
	{
		DrawChar("Quitting from GAMEPLAY", 0.3f, 0.6f);
		DrawNum(5 - totalTime, 0.5f, 0.5f);
		if (totalTime > 5)
			Game.ChangeState(UNLOAD);
	}
}

void Unload()		//UNLOAD THE GAME AND EXIT
{
	Shutdown();
}