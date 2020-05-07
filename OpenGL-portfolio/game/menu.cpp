#pragma once
#include "menu.h"

#include "sceneManager.h"
#include "stage.h"
Texture* menuBg;
Texture* menuBanner;
Texture* tex;

void loadMenu()
{
	printf("loadMenu()\n");

	menuBg = createImage("assets/menu/menuBg.jpg");
	menuBanner = createImage("assets/menu/Banner.png");
	audioPlay(3);
	createPopMenuBtn();
	
	createPopQuitAnswer();
}

void freeMenu()
{

	free(menuBg);
	free(menuBanner);
	free(tex);
	freePopMenuBtn();
}

void drawMenu(float dt)
{
	//printf("drawMenu()\n");
	iGraphics* g = iGraphics::instance();
	drawImage(menuBg, 0, 0, TOP | LEFT);



	g->init(600, 300);
	g->fillRect(0, 0, 600, 300,10);
	g->drawString(0, 0, TOP | LEFT, "김시윤 포트폴리오\n 임시텍스처! \n위치만 잡음");
	tex = g->getTexture();

	drawImage(tex, devSize.width / 2 - 300, devSize.height / 2 - 500, TOP | LEFT);

	//fillRect(devSize.width / 2 - 300, devSize.height / 2 - 500, 600, 300, 10);

	drawPopMenuBtn(dt);
	showPopMenuBtn(true);

	drawPopQuitAnswer(dt);
}

void keyMenu(iKeyState stat, iPoint point)
{
	if (keyPopQuitAnswer(stat, point))
		return;

	if (keyPopSettings(stat, point))
		return;
	
	if (keyPopMenuBtn(stat, point))
		return;
}


//---------------PopMenuBtn-----------------------//

const char* strSlot[3] = { "Game Start", "Settings", "Quit" };

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
			iSize size;

	

			//g->fillRect(0, 0, size.width, size.height);
			//g->drawString(size.width/2, size.height/2, HCENTER | VCENTER, strSlot[i]);
			
			igImage* ig = g->createIgImage("assets/menu/menuBtn%d.png", j);
			size = iSizeMake(g->getIgImageWidth(ig)*2, g->getIgImageHeight(ig)*2);
			g->init(size);
			
			g->drawImage(ig, 0, 0, 2.0,2.0,TOP | LEFT);
		
			g->drawString(size.width/2, size.height/2, VCENTER | HCENTER, strSlot[i]);
			tex = g->getTexture();
			
			img->addObject(tex);
			freeImage(tex);
		
		}
		//img->_aniDt = 3.0f;
		//img->animation = true;
		img->position = iPointMake(0, i*150);
		pop->addObject(img);
		imgMenuBtn[i] = img;		
	}

	pop->openPosition = iPointMake((devSize.width / 2)-310, devSize.height / 2 -100);
	pop->closePosition = iPointMake((devSize.width / 2)-310, devSize.height / 2 - 100);

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

		if (i < 1)
		{
			printf("selectd = %d\n", i);
			METHOD m = loadStage;
			setLoading(gs_stage, freeMenu, m);
			
		}
		else
		{
			//extern bool runWnd;
			showPopQuitAnswer(true);
			//게임 종료 확인팝업창 만들기
			//runWnd = false;
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






iPopup* PopMenuSettings;
iImage** PopMenuSettingsBtn;

void createPopSettings()
{
	iPopup* pop = new iPopup(iPopupStyleZoom);

	
}

void freePopSettings()
{
}

void drawPopSettings(float dt)
{
}

bool keyPopSettings(iKeyState stat, iPoint point)
{
	return false;
}

void showPopSettings(bool show)
{
}







iPopup* PopQuitAnswer;
iImage** PopQuitAnswerBtn;

const char* btnSlot[2] = { "Okay", "No" };
void createPopQuitAnswer()
{
	iPopup* pop = new iPopup(iPopupStyleZoom);
	iGraphics* g = iGraphics::instance();
	//iSize size = iSizeMake(1280, 720);
	iSize size;
	
	PopQuitAnswerBtn = (iImage**)malloc(sizeof(iImage*) *3); // 0: background 1: yes 2: no

	setStringBorder(0);
	setStringBorderRGBA(0, 0, 0, 0);
	setStringRGBA(0, 0, 0, 1);
	setStringSize(50);

	igImage* ig = g->createIgImage("assets/menu/popBg.png");
	size = iSizeMake(g->getIgImageWidth(ig) * 2.5, g->getIgImageHeight(ig) * 2.5);
	g->init(size);
	g->drawImage(ig, 0, 0, 2.5, 2.5, TOP | LEFT);
	g->drawString(size.width / 2, size.height / 2, VCENTER|HCENTER, "Do you want exit?");
	Texture* btnTex;
	btnTex = g->getTexture();
	
	iImage* img = new iImage();

	img->addObject(btnTex);
	freeImage(btnTex);


	pop->addObject((img));
	//PopQuitAnswerBtn[0] = img; // Background


	

	for (int i = 0; i < 2; i++) // 네, 아니오 btn
	{
		iImage* answerBtn = new iImage();
		
		for (int j = 0; j < 2; j++) 
		{
			
			if (j == 0) // off
			{
				setRGBA(1, 1, 1, 1);
				igImage* bg = g->createIgImage("assets/menu/BTN0.png");
				iSize btnSize = iSizeMake(g->getIgImageWidth(bg) * 3.0, g->getIgImageHeight(bg) * 2);
				g->init(btnSize);
				g->drawImage(bg, 0, 0, 3.0, 2.0, TOP | LEFT);
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnSlot[i]);
				btnTex = g->getTexture();
				printf("white\n");
			}

			else //on
			{
				setRGBA(1, 0, 0, 1);
				igImage* bg = g->createIgImage("assets/menu/BTN0.png");
				iSize btnSize = iSizeMake(g->getIgImageWidth(bg) * 3.0, g->getIgImageHeight(bg) * 2);
				g->init(btnSize);
				g->drawImage(bg, 0, 0, 3.0, 2.0, TOP | LEFT);
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnSlot[i]);
				btnTex = g->getTexture();
				printf("red\n");
			}

			answerBtn->addObject(btnTex);
			freeImage(btnTex);
		}
		
		answerBtn->position = iPointMake(size.width/2 - 460 + (550 * i), 450);
		pop->addObject(answerBtn);

		PopQuitAnswerBtn[i] = answerBtn;

	}




	pop->openPosition = iPointMake((devSize.width / 2)-size.width/2, devSize.height / 2 -size.height/2);
	pop->closePosition = iPointMake((devSize.width / 2)-size.width/2, devSize.height / 2 - size.height/2);
	pop->methodDrawBefore = drawPopQuitAnswerBefore;
	PopQuitAnswer = pop;
	
}

void freePopQuitAnswer()
{
	delete PopQuitAnswer;
	
}

void drawPopQuitAnswer(float dt)
{
	PopQuitAnswer->paint(dt);
}

bool keyPopQuitAnswer(iKeyState stat, iPoint point)
{
	if (PopQuitAnswer->bShow == false)
		return false;

	if (PopQuitAnswer->stat != iPopupStatProc)
		return true;
	
	int i, j = -1;

	switch (stat)
	{
		case iKeyStateBegan:
		{
			i = PopQuitAnswer->selected;

			printf("selectd = %d\n", i);
			if (i == -1)
				break;

			if (i == 0) // OkayBtn
			{
				extern bool runWnd;
				runWnd = false; //종료!
			}
			else if (i == 1) // NoBtn
			{
				PopQuitAnswer->show(false); // 창 닫음
			}
			break;
		}
	
		case iKeyStateMoved:
		{
			for (i = 0; i < 2; i++)
			{
				if (containPoint(point, PopQuitAnswerBtn[i]->touchRect(PopQuitAnswer->closePosition)))
				{
					j = i;
					break;
				}
			}
			PopQuitAnswer->selected = j;
			break;

		}

		case iKeyStateEnded:
			break;
	}



	return true;
}

void showPopQuitAnswer(bool show)
{
	PopQuitAnswer->show(show);
}

void drawPopQuitAnswerBefore(iPopup* me, float dt)
{
	for (int i = 0; i < 2; i++)
	{
		PopQuitAnswerBtn[i]->setTexAtIndex(i == PopQuitAnswer->selected);
	}
}
