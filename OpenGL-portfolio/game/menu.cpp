#pragma once
#include "menu.h"

#include "sceneManager.h"
#include "stage.h"
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
	//printf("drawMenu()\n");
	iGraphics* g = iGraphics::instance();
	Texture* tex;
	drawImage(menuBg, 0, 0, TOP | LEFT);

	g->init(600, 300);
	g->fillRect(0, 0, 600, 300,10);
	g->drawString(0, 0, TOP | LEFT, "김시윤 포트폴리오\n 임시텍스처! \n위치만 잡음");
	tex = g->getTexture();

	drawImage(tex, devSize.width / 2 - 300, devSize.height / 2 - 500, TOP | LEFT);

	//fillRect(devSize.width / 2 - 300, devSize.height / 2 - 500, 600, 300, 10);

	drawPopMenuBtn(dt);
	showPopMenuBtn(true);
	
}

void keyMenu(iKeyState stat, iPoint point)
{
	if (keyPopMenuBtn(stat, point))
		return;
}


//---------------PopMenuBtn-----------------------//

const char* strSlot[3] = { "게임시작", "게임설정", "게임종료" };

iPopup* PopMenuBtn;
iImage** imgMenuBtn;

void drawPopMenuBefore(iPopup* me, float dt);

void createPopMenuBtn()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(350, 100);
	imgMenuBtn = (iImage**)malloc(sizeof(iImage*) * 3);
	setStringBorder(0);
	setStringBorderRGBA(0, 0, 0, 0);
	setStringRGBA(0, 0, 0, 1);
	setStringSize(50);

	for(int i = 0; i <3; i++)
	{
		iImage* img = new iImage();
		for (int j = 0; j < 2; j++)
		{
			Texture* tex;
			g->init(size);

			if (j == 0)
				setRGBA(1, 1, 1, 1);
			else if (j == 1)
				setRGBA(1, 0, 0, 1);

			g->fillRect(0, 0, size.width, size.height);
			g->drawString(size.width/2, size.height/2, HCENTER | VCENTER, strSlot[i]);
			tex = g->getTexture();
			img->addObject(tex);
			
		
		}
		//img->_aniDt = 3.0f;
		//img->animation = true;
		img->position = iPointMake(0, i*150);
		pop->addObject(img);
		imgMenuBtn[i] = img;		
	}

	pop->openPosition = iPointMake((devSize.width / 2)-175, devSize.height / 2 -100);
	pop->closePosition = iPointMake((devSize.width / 2)-175, devSize.height / 2 - 100);

	pop->methodDrawBefore = drawPopMenuBefore;

	PopMenuBtn = pop;
}

void drawPopMenuBefore(iPopup* me, float dt)
{
	for (int i = 0; i < 3; i++)
	{
		imgMenuBtn[i]->setTexAtIndex(i == PopMenuBtn->selected);
	}
}

void freePopMenuBtn()
{
	delete PopMenuBtn;
	free(imgMenuBtn);
}

void drawPopMenuBtn(float dt)
{
	PopMenuBtn->paint(dt);
}



bool keyPopMenuBtn(iKeyState stat, iPoint point)
{
	if (PopMenuBtn->bShow == false)
		return false;

	if (PopMenuBtn->stat != iPopupStatProc)
		return true;

	int i, j = -1;

	switch (stat)
	{
	case iKeyStateBegan :
		i = PopMenuBtn->selected;
		if (i == -1)
			break;

		if (i < 4)
		{
			printf("selectd = %d\n", i);
			METHOD m = loadStage;
			setLoading(gs_stage, freeMenu, m);
			
		}

		break;

	case iKeyStateMoved:
		for (i = 0; i < 3; i++)
		{
			if (containPoint(point, imgMenuBtn[i]->touchRect(PopMenuBtn->closePosition)))
			{
				j = i;
				break;
			}
		}
		PopMenuBtn->selected = j;
		break;

	case iKeyStateEnded:
		break;
	}

	return true;

}

void showPopMenuBtn(bool show)
{
	PopMenuBtn->show(show);
}
