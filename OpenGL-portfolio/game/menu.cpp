#pragma once
#include "menu.h"

Texture* menuBg;


void loadMenu()
{
	printf("loadMenu()\n");

	menuBg = createImage("assets/menu/menuBg.jpg");

	audioPlay(3);
	createPopMenuBtn();
	
	
}

void freeMenu()
{

	free(menuBg);
	freePopMenuBtn();
}

void drawMenu(float dt)
{
	printf("drawMenu()\n");

	drawImage(menuBg, 0, 0, TOP | LEFT);

#if 0 // 버튼이 위치할 좌표
	for (int i = 0; i < 3; i++)
		fillRect((devSize.width / 2) - 175, (250 * i) + 350, 350, 100);

#endif 

	drawPopMenuBtn(dt);
	showPopMenuBtn(true);
	
}

void keyMenu(iKeyState stat, iPoint point)
{
	if (keyPopMenuBtn(stat, point))
		return;
}


//---------------PopMenuBtn-----------------------//

iPopup* PopMenuBtn;
iImage** imgMenuBtn;
void createPopMenuBtn()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(350, 100);
	imgMenuBtn = (iImage**)malloc(sizeof(iImage*) * 3);

	for(int i = 0; i <3; i++)
	{
		iImage* img = new iImage();
		for(int j = 0; j <2; j++)
		{
			Texture* tex;
			g->init(size);

			if (j == 0)
				setRGBA(1, 1, 1, 1);
			else if (j == 1)
				setRGBA(1, 0, 0, 1);

			g->fillRect(0, 0, size.width, size.height);
			tex = g->getTexture();

// #bug 어제 여기까지함
			
			
		
		}


		
	}


	PopMenuBtn = pop;
}

void freePopMenuBtn()
{
	delete PopMenuBtn;
}

void drawPopMenuBtn(float dt)
{
	PopMenuBtn->paint(dt);
}

bool keyPopMenuBtn(iKeyState stat, iPoint point)
{
	return false;
}

void showPopMenuBtn(bool show)
{
	PopMenuBtn->show(show);
}
