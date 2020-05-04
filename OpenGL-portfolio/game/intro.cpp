#pragma once


#include "intro.h"
#include "main.h"
#include "sceneManager.h"

#include "menu.h"




iImage* next = (iImage*)malloc(sizeof(iImage));
Texture* bg;
Texture* title;
Texture* enter;

void loadIntro()
{
	static float rate = 0.0f;
	rate += 0.1f;
	
	
	printf("loadIntro()\n");
	
	bg = createImage("assets/intro/introbackground.png");

	//title = createImage("assets/intro/title.png");
	iGraphics* g = iGraphics::instance();
	{
		igImage* ig = g->createIgImage("assets/intro/title.png");
		iSize size = iSizeMake(g->getIgImageWidth(ig)/2.0, g->getIgImageHeight(ig)/2.0);
		g->init(size);

		g->drawImage(ig, 0, 0, 1.0/2, 1.0/2, TOP | LEFT);
		g->freeIgImage(ig);

		title = g->getTexture();

		ig = g->createIgImage("assets/intro/enter.png");
		size = iSizeMake(g->getIgImageWidth(ig),  g->getIgImageHeight(ig));
		g->init(size);

		g->drawImage(ig, 0, 0, 1.0, 1.0, TOP | LEFT);
		g->freeIgImage(ig);

		enter = g->getTexture();
	}

}

void freeIntro()
{
	printf("freeIntro()n\n");

	free(bg);
	free(title);
	free(enter);

	
}

void drawIntro(float dt)
{
	static float r = 0.0f;

	r += 0.3f;

	float rateSize = _sin(r);

	if (rateSize < 0.4f)
		rateSize = 0.4f;
	
	
	printf("%f\n", r);
	printf("drawIntro()\n");
	setRGBA(1, 1, 1, 1);

	drawImage(bg, 0, 0, TOP | LEFT);
	//fillRect(0, 0, devSize.width, devSize.height); // Intro Background
	

	drawImage(title, devSize.width / 2, 450, HCENTER | VCENTER);


	drawImage(
		enter, devSize.width / 2, devSize.height / 2 + 300, 0, 0, enter->potWidth, enter->potHeight, VCENTER|HCENTER, rateSize, rateSize, 0,1, REVERSE_NONE );
	//drawImage(enter, devSize.width / 2 , devSize.height /2 + 300, HCENTER | VCENTER);
	setRGBA(1, 1, 1, 1);
	
	
	

	
}

void keyIntro(iKeyState stat, iPoint point)
{
	
}


// ------------------------------------------------
//	Press Any Key PopUP
// ------------------------------------------------



