#include "game.h"


#include "intro.h"
#include "menu.h"
#include "sceneManager.h"


#define SOUND_NUM 128


void loadGame()
{
	AudioInfo soundAssets[SOUND_NUM] = {
							{ "assets/intro/sound/bgm.wav", true, 0.5f},
							{ "assets/intro/sound/okay.wav", false, 1.0f},
							{ "assets/intro/sound/SHOT.wav", false, 1.0f},
	};


	loadAudio(soundAssets, 2);

	audioPlay(0);

		
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
