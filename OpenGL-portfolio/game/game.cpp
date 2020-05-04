#include "game.h"


#include "intro.h"
#include "menu.h"
#include "sceneManager.h"

void loadGame()
{
	AudioInfo sound[3] = { {"assets/intro/sound/2.wav",false, 0.6f},
							{"assets/intro/sound/intro.wav",false, 0.6f},
							{"assets/intro/sound/intro.wav",true, 1.0f}, };
	loadAudio(sound, 3);
	audioPlay(2);
	
	loadIntro();
	gameState = gs_intro;
}

void freeGame()
{
	switch(gameState)
	{
	case gs_intro: freeIntro();	break;
	case gs_menu:	freeMenu(); break;
	case gs_proc:	break;
	case gs_ending: break;
	}

	freeAudio();
}

void drawGame(float dt)
{
	switch(gameState)
	{
	case gs_intro:	drawIntro(dt); break;
	case gs_menu:	drawMenu(dt);  break;
	case gs_proc:	break;
	case gs_ending:	break;
		
	}

	drawLoading(dt);
}

void keyGame(iKeyState stat, iPoint point)
{
	if (keyLoading(stat, point))
		return;

	switch(gameState)
	{
	case gs_intro:	keyIntro(stat, point);	break;
	case gs_menu:	keyMenu(stat, point);	break;
	case gs_proc:		break;
	case gs_ending:		break;
	}
}
