#include "game.h"


#include "intro.h"
#include "menu.h"
#include "sceneManager.h"
#include "trailer.h"
#include "stage.h"
#include "ending.h"
#include "endstage.h"
#include "vilege.h"
#define SOUND_NUM 16


void loadGame()
{
	AudioInfo soundAssets[SOUND_NUM] = {
							{ "assets/intro/sound/bgm.wav", true, 7.0f},
							{ "assets/intro/sound/okay.wav", false, 1.0f},
							{ "assets/intro/sound/SHOT.wav", false, 1.0f},
							{"assets/menu/sound/menuBGM.wav", true, 1.0f},
							{"assets/stage/hero/Knight/skill/skill1sound.wav", false, 1.0f},
							{"assets/stage/goblin/sound/playerhit.wav", false, 1.0f},
							{"assets/menu/sound/levelup.wav", false, 1.0f},
							{"assets/menu/sound/getitem.wav",false, 1.0f},
							{"assets/stage/hero/Knight/skill2/skill2.wav", false, 1.0f},
	};


	loadAudio(soundAssets, 9);

	loadIntro();
	gameState = gs_intro;

	createPopQuitAnswer();

	//loadTrailer();
	//gameState = gs_trailer;
	audioPlay(0);

		
}

void freeGame()
{
	freePopQuitAnswer();

	switch(gameState)
	{
	case gs_intro: freeIntro();	break;
	case gs_menu:	freeMenu(); break;
	case gs_stage:	freeStage(); break;
	case gs_ending: freeEnding(); break;
	case gs_trailer: freeTrailer(); break;
	case gs_endStage: freeEndStage(); break;
	case gs_villege: freeVillege(); break;
	}

	freeAudio();
}

void drawGame(float dt)
{
	switch(gameState)
	{
	case gs_intro:	drawIntro(dt); break;
	case gs_menu:	drawMenu(dt);  break;
	case gs_stage:  drawStage(dt);	break;
	case gs_ending:	drawEnding(dt);  break;
	case gs_trailer: drawTrailer(dt); break;
	case gs_endStage: drawEndStage(dt); break;
	case gs_villege: drawVillege(dt); break;
		
	}

	drawPopQuitAnswer(dt);

	drawLoading(dt);
}

void keyGame(iKeyState stat, iPoint point)
{
	if (keyLoading(stat, point) ||
		keyPopQuitAnswer(stat, point))
		return;

	switch(gameState)
	{
	case gs_intro:	keyIntro(stat, point);	break;
	case gs_menu:	keyMenu(stat, point);	break;
	case gs_stage:	keyStage(stat, point);	break;
	case gs_ending:	keyEnding(stat, point);	break;
	case gs_trailer: keyTrailer(stat, point); break;
	case gs_endStage: keyEndStage(stat, point); break;
	case gs_villege: keyVilliege(stat, point); break;
	}
}

iPopup* PopQuitAnswer;
iImage** PopQuitAnswerBtn;

const char* btnSlot[2] = { "Okay", "No" };
void createPopQuitAnswer()
{
	iPopup* pop = new iPopup(iPopupStyleZoom);
	iGraphics* g = iGraphics::instance();
	//iSize size = iSizeMake(1280, 720);
	iSize size = iSizeMake(690, 360);

	PopQuitAnswerBtn = (iImage**)malloc(sizeof(iImage*) * 3); // 0: background 1: yes 2: no

	setStringBorder(0);
	setStringBorderRGBA(0, 0, 0, 0);
	setStringRGBA(0, 0, 0, 1);
	setStringSize(50);

	igImage* ig = g->createIgImage("assets/menu/popBg.png");
	size = iSizeMake(g->getIgImageWidth(ig) * 2.5, g->getIgImageHeight(ig) * 2.5);
	g->init(size);
	g->drawImage(ig, 0, 0, 2.5, 2.5, TOP | LEFT);
	g->drawString(size.width / 2, size.height / 2, VCENTER | HCENTER, "Do you want exit?");
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

		answerBtn->position = iPointMake((size.width / 2) - 300 + (550 * i), 450);
		pop->addObject(answerBtn);

		PopQuitAnswerBtn[i] = answerBtn;

	}




	pop->openPosition = iPointMake((devSize.width / 2) - size.width / 2, devSize.height / 2 - size.height / 2);
	pop->closePosition = iPointMake((devSize.width / 2) - size.width / 2, devSize.height / 2 - size.height / 2);
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

void drawPopQuitAnswerBefore(iPopup* me, iPoint p, float dt)
{
	for (int i = 0; i < 2; i++)
	{
		PopQuitAnswerBtn[i]->setTexAtIndex(i == PopQuitAnswer->selected);
	}
}

