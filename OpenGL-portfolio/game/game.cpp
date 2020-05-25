#include "game.h"


#include "intro.h"
#include "menu.h"
#include "sceneManager.h"
#include "trailer.h"
#include "stage.h"
#include "ending.h"
#include "endstage.h"
#include "vilege.h"
#define SOUND_NUM 16


void loadGame()
{
	AudioInfo soundAssets[SOUND_NUM] = {
							{ "assets/intro/sound/bgm.wav", true, 1.0f},
							{ "assets/intro/sound/okay.wav", false, 1.0f},
							{ "assets/intro/sound/SHOT.wav", false, 1.0f},
							{"assets/menu/sound/menuBGM.wav", true, 1.0f},
							{"assets/stage/hero/Knight/skill/skill1sound.wav", false, 1.0f},
	};


	loadAudio(soundAssets, 5);


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
	case gs_stage:	freeStage(); break;
	case gs_ending: freeEnding(); break;
	case gs_trailer: freeTrailer(); break;
	case gs_endStage: freeEndStage(); break;
	case gs_villege: freeVillege(); break;
	}

	freeAudio();
}

void drawGame(float dt)
{
	switch(gameState)
	{
	case gs_intro:	drawIntro(dt); break;
	case gs_menu:	drawMenu(dt);  break;
	case gs_stage:  drawStage(dt);	break;
	case gs_ending:	drawEnding(dt);  break;
	case gs_trailer: drawTrailer(dt); break;
	case gs_endStage: drawEndStage(dt); break;
	case gs_villege: drawVillege(dt); break;
		
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
	case gs_stage:	keyStage(stat, point);	break;
	case gs_ending:	keyEnding(stat, point);	break;
	case gs_trailer: keyTrailer(stat, point); break;
	case gs_endStage: keyEndStage(stat, point); break;
	case gs_villege: keyVilliege(stat, point); break;
	}
}
