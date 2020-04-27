#include "game.h"

#include "sceneManager.h"

void loadGame()
{
	
}

void freeGame()
{
	switch(gameState)
	{
	case gs_intro:	break;
	case gs_menu:	break;
	case gs_proc:	break;
	case gs_ending: break;
	}
}

void drawGame(float dt)
{
	switch(gameState)
	{
	case gs_intro:	break;
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
	case gs_intro:		break;
	case gs_menu:		break;
	case gs_proc:		break;
	case gs_ending:		break;
	}
}
