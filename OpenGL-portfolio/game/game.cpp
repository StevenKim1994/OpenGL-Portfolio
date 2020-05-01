#include "game.h"


#include "intro.h"
#include "sceneManager.h"

void loadGame()
{
	loadIntro();
	gameState = gs_intro;
}

void freeGame()
{
	switch(gameState)
	{
	case gs_intro: freeIntro();	break;
	case gs_menu:	break;
	case gs_proc:	break;
	case gs_ending: break;
	}
}

void drawGame(float dt)
{
	switch(gameState)
	{
	case gs_intro:	drawIntro(dt); break;
	case gs_menu:	break;
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
	case gs_menu:		break;
	case gs_proc:		break;
	case gs_ending:		break;
	}
}
