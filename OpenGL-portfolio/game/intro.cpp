#pragma once


#include "intro.h"
#include "main.h"
#include "sceneManager.h"

#include "menu.h"




iImage* next = (iImage*)malloc(sizeof(iImage));
Texture* bg;
Texture* title;
void loadIntro()
{
	printf("loadIntro()\n");
	bg = createImage("assets/intro/introbackground.png");

	//title = createImage("assets/intro/title.png");
	iGraphics* g = iGraphics::instance();
	{
		igImage* ig = g->createIgImage("assets/intro/title.png");
		iSize size = iSizeMake(g->getIgImageWidth(ig)/3.0, g->getIgImageHeight(ig)/3.0);
		g->init(size);

		g->drawImage(ig, 0, 0, 1.0/3, 1.0/3, TOP | LEFT);
		g->freeIgImage(ig);

		title = g->getTexture();
	}
	createPressPop();

	showPressPop(true);
}

void freeIntro()
{
	printf("freeIntro()n\n");

	free(bg);
	freePressPop();
}

void drawIntro(float dt)
{


	printf("drawIntro()\n");
	setRGBA(1, 1, 1, 1);

	drawImage(bg, 0, 0, TOP | LEFT);
	//fillRect(0, 0, devSize.width, devSize.height); // Intro Background
	

	drawImage(title, devSize.width / 2, 100, HCENTER | VCENTER);
	
	setRGBA(1, 1, 1, 1);
	drawPressPop(dt);
	
	

	
}

void keyIntro(iKeyState stat, iPoint point)
{
	keyPressPop(stat, point);
}


// ------------------------------------------------
//	Press Any Key PopUP
// ------------------------------------------------


iPopup* pressPop;
void createPressPop()
{
	setRGBA(1, 1, 1, 1);
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iImage* img = new iImage();
	Texture* tex;

	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(512, 30);
	g->init(size);
	
	setStringRGBA(0, 0, 0, 1);
	setStringSize(30);
	setStringBorder(0);

	g->drawString(0 , 0, TOP|LEFT, "아무키나 눌러주세요...\n");

	tex = g->getTexture();

	img->addObject(tex);

	freeImage(tex);

	pop->addObject(img);
	

	iPoint p = iPointMake(devSize.width /2 -128, devSize.height /2 +300);

	pop->openPosition = p;
	pop->closePosition = p;

	pressPop = pop;
}

void freePressPop()
{
	delete pressPop;
}

void showPressPop(bool show)
{
	pressPop->show(show);
}

void drawPressPop(float dt)
{
	
	pressPop->paint(dt);
	

}

bool keyPressPop(iKeyState stat, iPoint point)
{
	
	if (stat == iKeyStateBegan)
	{
		gameState = gs_menu;
		setLoading(gs_menu, freeMenu, loadMenu);
	}

	return false;
}

