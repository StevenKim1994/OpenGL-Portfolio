#pragma once
#include "menu.h"

#include "sceneManager.h"
#include "stage.h"
Texture* menuBg;
Texture* menuBanner;
Texture* tex;

void loadMenu()
{

	menuBg = createImage("assets/menu/menuBg.jpg");
	menuBanner = createImage("assets/menu/Banner.png");
	tex = createImage("assets/menu/mainlogo.png");
	
	createPopMenuBtn();
	createPopSettings();
	createPopQuitAnswer();
	
	audioPlay(3);
}

void freeMenu()
{
	free(menuBg);
	free(menuBanner);
	free(tex);
	freePopMenuBtn();
	freePopSettings();
}

void drawMenu(float dt)
{

	drawImage(menuBg, 0, 0, TOP | LEFT);
	drawImage(tex, devSize.width / 2 , 150, VCENTER | HCENTER); // banner

	drawPopMenuBtn(dt);
	showPopMenuBtn(true);

	drawPopSettings(dt);
	drawPopQuitAnswer(dt);
}

void keyMenu(iKeyState stat, iPoint point)
{
	if (keyPopSettings(stat, point))
		return;

	if (keyPopQuitAnswer(stat, point))
		return;

	
	if (keyPopMenuBtn(stat, point))
		return;
}


//---------------PopMenuBtn-----------------------//

const char* strSlot[3] = { "Game Start", "Settings", "Quit" };

iPopup* PopMenuBtn;
iImage** imgMenuBtn;

void drawPopMenuBefore(iPopup* me, iPoint p, float dt);

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


			
			igImage* ig = g->createIgImage("assets/menu/menuBtn%d.png", j);
			size = iSizeMake(g->getIgImageWidth(ig)*2, g->getIgImageHeight(ig)*2);
			g->init(size);
			
			g->drawImage(ig, 0, 0, 2.0,2.0,TOP | LEFT);
		
			g->drawString(size.width/2, size.height/2, VCENTER | HCENTER, strSlot[i]);
			tex = g->getTexture();
			
			img->addObject(tex);
			freeImage(tex);
		
		}
	
		img->position = iPointMake(0, i*150);
		pop->addObject(img);
		imgMenuBtn[i] = img;		
	}

	pop->openPosition = iPointMake((devSize.width / 2)-310, devSize.height / 2 -100);
	pop->closePosition = iPointMake((devSize.width / 2)-310, devSize.height / 2 - 100);

	pop->methodDrawBefore = drawPopMenuBefore;

	PopMenuBtn = pop;
}

void drawPopMenuBefore(iPopup* me, iPoint p, float dt)
{
	for (int i = 0; i < 3; i++)
	{
		imgMenuBtn[i]->setTexAtIndex(i == PopMenuBtn->selected);
	}
}

void drawPopMenuSettingsBefore(iPopup* me, float dt)
{
}


void freePopMenuBtn()
{
	delete PopMenuBtn;
	free(imgMenuBtn);
}

void drawPopMenuBtn(float dt)
{
	PopMenuBtn->paint(dt);

	int key = PopMenuBtn->selected;
	if (getKeyDown() & keyboard_up)
	{
		audioPlay(1); // 버튼음 재생
		key--;
		if (key < 0)
			key = 0;
	
	
	}
	else if (getKeyDown() & keyboard_down)
	{
		audioPlay(1); // 버튼음 재생
		key++;
		if (key > 2)
			key = 2;
	}
	PopMenuBtn->selected = key;

	if(getKeyDown() & keyboard_enter)
	{
		audioPlay(1); // 버튼음 재생
		if (key == 0)
		{
			setLoading(gs_stage, freeMenu, loadStage);
		}

		else if (key == 1)
		{
			showPopSettings(true);
		}

		else
		{
			showPopQuitAnswer(true);
		}
	}
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
	case iKeyState::iKeyStateBegan :
		i = PopMenuBtn->selected;
		if (i == -1)
			break;

		if (i == 0)
		{
			setLoading(gs_stage, freeMenu, loadStage);
		}

		else if (i == 1)
		{
			showPopSettings(true);
		}

		else
		{
			showPopQuitAnswer(true);
		}

		break;

	case iKeyState::iKeyStateMoved:
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

	case iKeyState::iKeyStateEnded:
		break;
	}

	return true;

}

void showPopMenuBtn(bool show)
{
	PopMenuBtn->show(show);
}



//----------- PopMenuSettings ------------------------

iPopup* PopMenuSettings;
iImage** PopMenuSettingsBtn;
float bgmPop, sfxPop; // 배경음, 효과음
const char* btnName[3] = {"BGM SOUND" ,"EFFECT SOUND" ,"exit"};

void drawPopMenuSettingsBefore(iPopup* me, float dt);

void createPopSettings()
{
	iPopup* pop = new iPopup(iPopupStyleZoom);

	PopMenuSettingsBtn = (iImage**)malloc(sizeof(iImage*) * 3); // 0:bgm 1:sfx 2:exit
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(690, 360);
	
	igImage* ig = g->createIgImage("assets/menu/popBg.png");
	size = iSizeMake(g->getIgImageWidth(ig) * 2.5, g->getIgImageHeight(ig) * 2.5);
	g->init(size);
	g->drawImage(ig, 0, 0, 2.5, 2.5, TOP | LEFT);
	g->drawString(devSize.width / 2, 100, HCENTER | VCENTER, "Game Settings");
	

	Texture* bgTex;
	iImage* bgImage = new iImage();
	bgTex = g->getTexture();
	bgImage->addObject(bgTex);
	freeImage(bgTex);
	pop->addObject(bgImage);

	for (int i = 0; i < 2; i++) // setting bar
	{
		// name
		Texture* opName;
		iImage* img = new iImage();
		igImage* ig = g->createIgImage("assets/menu/BTN0.png");
		iSize btnSize = iSizeMake(g->getIgImageWidth(ig)*2, g->getIgImageHeight(ig));
		setStringSize(17);
		setStringRGBA(0, 0, 0, 1);
		g->init(btnSize);
		g->drawImage(ig, 0, 0, 2.0, 1.0, TOP | LEFT);
		g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnName[i]);
	
		opName = g->getTexture();
		img->addObject(opName);
		freeImage(opName);
		img->position = iPointMake(size.width - size.width + 150, i * 200 + 200);
		pop->addObject(img);



		//range bar
		Texture* rangeBar;
		iImage* barImg = new iImage();
		iSize settingBar = iSizeMake(500, 30);
		g->init(settingBar);
		setRGBA(0, 0, 1, 1);
		g->fillRect(0, 0, settingBar.width, settingBar.height,10);
		
		rangeBar = g->getTexture();
		barImg->addObject(rangeBar);
		freeImage(rangeBar);
		barImg->position = iPointMake(size.width - size.width + 150, i * 270 + 270);
		pop->addObject(barImg);
		setRGBA(1, 1, 1, 1);

		


	}


	{ // exit btn
		iImage* img = new iImage();
		Texture* tex;

		igImage* ig = g->createIgImage("assets/menu/BTN1.png");
		iSize btnSize = iSizeMake(g->getIgImageWidth(ig)*0.5, g->getIgImageHeight(ig)*0.5);
		setStringSize(17);
		setStringRGBA(1, 1, 1, 1);
		g->init(btnSize);
		g->drawImage(ig, 0, 0, 0.5, 0.5, TOP | LEFT);

		tex = g->getTexture();
		img->addObject(tex);
		freeImage(tex);

		img->position = iPointMake(size.width - tex->width, 0);


		pop->addObject(img);
		PopMenuSettingsBtn[0] = img;

	}
	
	{ // sound setting btn

		for (int i = 0; i < 2; i++)
		{
			iImage* img = new iImage();
			Texture* tex;

			igImage* ig = g->createIgImage("assets/menu/settingIcon.png");
			iSize btnSize = iSizeMake(g->getIgImageWidth(ig), g->getIgImageHeight(ig));
			g->init(btnSize);
			g->drawImage(ig, 0, 0, 1.0, 1.0, TOP | LEFT);

			tex = g->getTexture();
			img->addObject(tex);
			freeImage(tex);

			img->position = iPointMake(size.width / 2 +40, (size.height / 2 -70) *(i+1));

			pop->addObject(img);
			PopMenuSettingsBtn[i + 1] = img;

			printf("%f %f\n", img->position.x, img->position.y);
		
		
		
		}

	}


	pop->openPosition = iPointMake((devSize.width / 2) - size.width / 2, devSize.height / 2 - size.height / 2);
	pop->closePosition = iPointMake((devSize.width / 2) - size.width / 2, devSize.height / 2 - size.height / 2);

	PopMenuSettings = pop;

	
}



	


void freePopSettings()
{
	
	delete PopMenuSettings;
}

void drawPopSettings(float dt)
{
	PopMenuSettings->paint(dt);
}


bool touching;
iPoint prevPoint;

bool keyPopSettings(iKeyState stat, iPoint point)
{
	printf("%f %f\n", point.x, prevPoint.x);
	
	
	if (PopMenuSettings->bShow == false)
		return false;

	if (PopMenuSettings->stat != iPopupStatProc)
		return true;

	int i, j = -1;

	switch (stat)
	{
	case iKeyState::iKeyStateBegan:
	{
	
	
		i = PopMenuSettings->selected;

		if (i == -1) break;
			
		if (i == 0)
		{
			showPopSettings(false);
			//PopMenuSettings->show(false);
		}
		else //if(i > 0 && i < 3)
		{
			touching = true;
			prevPoint = point;
		}
		break;

	}
	case iKeyState::iKeyStateMoved:
	
		if(touching)
		{
			
			i = PopMenuSettings->selected;
			if(i > 0)
			{
				iImage* img = PopMenuSettingsBtn[i];
				//printf("%f %f\n", img->position.x, img->position.y);
				img->position.x += (point - prevPoint).x;
				if (img->position.x > 621)
					img->position.x = 620;
				else if (img->position.x < 190)
					img->position.x = 190;
				prevPoint = point;

				
			}
			
		}
		else
		{
			for (i = 0; i < 3; i++)
			{
				if (containPoint(point, PopMenuSettingsBtn[i]->touchRect(PopMenuSettings->closePosition)))
				{

					j = i;
					break;
				}
			}
			PopMenuSettings->selected = j;
		}
		break;



	
	case iKeyState::iKeyStateEnded:
	{
		touching = false;
		i = PopMenuSettings->selected;
		if (i == 1) // bgm sound
		{
			float r = (PopMenuSettingsBtn[i]->position.x - 150) / 630;
			bgmPop = r;
			audioVolume(bgmPop, sfxPop, 2);
		}
		else if (i == 2) // effect sound
		{
			float r = (PopMenuSettingsBtn[i]->position.x - 150) / 630;
			sfxPop = r;
			audioVolume(bgmPop, sfxPop, 2);

		}




	}
	break;
	}


	return true;
}

void showPopSettings(bool show)
{
	PopMenuSettings->show(show);
}


//-------------- popSettings -----------------//





iPopup* PopQuitAnswer;
iImage** PopQuitAnswerBtn;

const char* btnSlot[2] = { "Okay", "No" };
void createPopQuitAnswer()
{
	iPopup* pop = new iPopup(iPopupStyleZoom);
	iGraphics* g = iGraphics::instance();
	//iSize size = iSizeMake(1280, 720);
	iSize size = iSizeMake(690, 360);
	
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

#define menuBtnSizeRateW 1.0f
#define	menuBtnSizeRateH 1.0f
	

	for (int i = 0; i < 2; i++) // 네, 아니오 btn
	{
		iImage* answerBtn = new iImage();
		
		for (int j = 0; j < 2; j++) 
		{
			
			if (j == 0) // off
			{
				setRGBA(1, 1, 1, 1);
				setStringSize(30);
				igImage* bg = g->createIgImage("assets/menu/BTN0.png");
				iSize btnSize = iSizeMake(g->getIgImageWidth(bg) * menuBtnSizeRateW, g->getIgImageHeight(bg) * menuBtnSizeRateH);
				g->init(btnSize);
				g->drawImage(bg, 0, 0, menuBtnSizeRateW, menuBtnSizeRateH, TOP | LEFT);
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnSlot[i]);
				btnTex = g->getTexture();

			}

			else //on
			{
				setRGBA(1, 0, 0, 1);
				setStringSize(30);
				igImage* bg = g->createIgImage("assets/menu/BTN0.png");
				iSize btnSize = iSizeMake(g->getIgImageWidth(bg) * menuBtnSizeRateW, g->getIgImageHeight(bg) * menuBtnSizeRateH);
				g->init(btnSize);
				g->drawImage(bg, 0, 0, menuBtnSizeRateW, menuBtnSizeRateH, TOP | LEFT);
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnSlot[i]);
				btnTex = g->getTexture();
			}

			answerBtn->addObject(btnTex);
			freeImage(btnTex);
		}
		
		answerBtn->position = iPointMake( (size.width/2)-300 + (550 * i), 450);
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
		case iKeyState::iKeyStateBegan:
		{
			i = PopQuitAnswer->selected;

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
	
		case iKeyState::iKeyStateMoved:
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

		case iKeyState::iKeyStateEnded:
			break;
	}



	return true;
}

void showPopQuitAnswer(bool show)
{
	PopQuitAnswer->show(show);
}

void drawPopQuitAnswerBefore(iPopup* me, iPoint p,float dt)
{
	for (int i = 0; i < 2; i++)
	{
		PopQuitAnswerBtn[i]->setTexAtIndex(i == PopQuitAnswer->selected);
	}
}


