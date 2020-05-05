#include "game.h"


#include "intro.h"
#include "menu.h"
#include "sceneManager.h"
#include "trailer.h"

#define SOUND_NUM 128


void loadGame()
{
	AudioInfo soundAssets[SOUND_NUM] = {
							{ "assets/intro/sound/bgm.wav", true, 1.0f},
							{ "assets/intro/sound/okay.wav", false, 1.0f},
							{ "assets/intro/sound/SHOT.wav", false, 1.0f},
							{"assets/menu/sound/menuBGM.wav", true, 1.0f}
	};


	loadAudio(soundAssets, 4);


	//loadTrailer();
	//gameState = gs_trailer;
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
	case gs_trailer: freeTrailer(); break;
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
	case gs_trailer: drawTrailer(dt); break;
		
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
	case gs_trailer: keyTrailer(stat, point); break;
	}
}
