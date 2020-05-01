#pragma once


#include "intro.h"
#include "main.h"
#include "sceneManager.h"




void loadIntro()
{
	printf("loadIntro()\n");
}

void freeIntro()
{
	printf("freeIntro()n\n");
}

void drawIntro(float dt)
{

	printf("drawIntro()\n");
	setRGBA(0, 0, 1, 1);

	fillRect(0, 0, devSize.width, devSize.height);

	
}

void keyIntro(iKeyState stat, iPoint point)
{
}
