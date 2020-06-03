#pragma once

#include "intro.h"
#include "main.h"
#include "sceneManager.h"

#include "menu.h"

#include "Flyeye.h"

Texture* bg;
Texture* title;
Texture* enter;

Flyeye** flyeyes;
Flyeye* flyeye;

static float mr = -0.35f;
static float mmr = 0.05f;
static float mm = 0.0f;
static float rate = 0.0f;
static float r = 0.0f;

void loadIntro()
{
	rate += 0.1f;
	bg = createImage("assets/intro/introbackground.png");
	iGraphics* g = iGraphics::instance();
	igImage* ig = g->createIgImage("assets/intro/enter.png");
	iSize size = iSizeMake(g->getIgImageWidth(ig),  g->getIgImageHeight(ig));
	g->init(size);

	g->drawImage(ig, 0, 0, 1.0, 1.0, TOP | LEFT);
	g->freeIgImage(ig);

	enter = g->getTexture();
	

	// create Flyeyes

	flyeyes = (Flyeye**)malloc(sizeof(Flyeye*) * 5);
	
	for(int i = 0; i<5; i++)
	{
		
		flyeye = new Flyeye();
		if (i % 2 == 0)
			flyeye->direction = 0;
		else
			flyeye->direction = 1;
		flyeye->setPosition(iPointMake(i * 300 + 100, i * 100 + 50));
		flyeyes[i] = flyeye;
		
	}

	audioPlay(2);
	createTitle();
	showTitle(true);
}

void freeIntro()
{
	for (int i = 0; i < 5; i++)
		delete flyeyes[i];

	free(flyeyes);

	free(bg);
	free(title);
	free(enter);

	freeTitle();
}
float resolutionRate = 200; // 1920x1080 : 300;

void drawIntro(float dt)
{
	r += 0.3f;
	float rateSize = _sin(r);

	if (rateSize < 0.4f)
		rateSize = 0.4f;

	setRGBA(1, 1, 1, 1);
	drawImage(bg, 0, 0, TOP | LEFT);
	
	mm += mmr;

	if (mm > 100.0f)
	{
		mr = -mr;
		mm = 0.0f;
		for (int i = 0; i < 5; i++)
		{
			if (flyeyes[i]->direction == 1)
				flyeyes[i]->direction = 0;
			else
				flyeyes[i]->direction = 1;
		}
	}
	
	//paint flyeyes
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			flyeyes[i]->setPosition(iPointMake(flyeyes[i]->getPosition().x + mr, flyeyes[i]->getPosition().y));

		else
			flyeyes[i]->setPosition(iPointMake(flyeyes[i]->getPosition().x - mr, flyeyes[i]->getPosition().y));

	}

	
	for (int i = 0; i < 5; i++)
		flyeyes[i]->paint(dt, iPointZero);

	

	drawImage(enter, devSize.width / 2, devSize.height / 2 + resolutionRate, 0, 0, enter->potWidth, enter->potHeight, VCENTER|HCENTER, rateSize, rateSize, 0,1, REVERSE_NONE );

	setRGBA(1, 1, 1, 1);
	
	if (getKeyDown() & keyboard_enter)
	{
		audioStop(0); // Intro BGM stop
		audioPlay(1); // 버튼음 재생
		setLoading(gs_menu, freeIntro, loadMenu);
	}

	drawTitle(dt);
	
}

void keyIntro(iKeyState stat, iPoint point)
{
	

}



// ------------------------------------------------
//	POP Title
// ------------------------------------------------

iPopup* popTitle;

void createTitle()
{
	iImage* img;
	iPopup* pop = new iPopup(iPopupStyleMove); // popTitle가 위에서 아래로 내려올것임.
	Texture* tex;


	iGraphics* g = iGraphics::instance();
	{

		igImage* ig = g->createIgImage("assets/intro/title.png");
		iSize size = iSizeMake(g->getIgImageWidth(ig) / 0.3, g->getIgImageHeight(ig) / 0.3);
		g->init(size);

		g->drawImage(ig, 0, 0, 0.3 , 0.3 , TOP | LEFT);

		tex = g->getTexture();
		g->freeIgImage(ig);
	}

	img = new iImage();
	img->addObject(tex);
	freeImage(tex);
	
	pop->addObject(img);

	
	iPoint op = iPointMake(devSize.width / 2 - resolutionRate, 0.0);
	
	pop->openPosition = op;
	
	iPoint cp = iPointMake(devSize.width / 2 - resolutionRate, devSize.height / 2-100);

	pop->closePosition = cp;

	popTitle = pop;

}

void freeTitle()
{
	delete popTitle;

}

void drawTitle(float dt)
{
	popTitle->paint(dt);
}

void keyTitle()
{
}

void showTitle(bool show)
{
	popTitle->show(show);
}

