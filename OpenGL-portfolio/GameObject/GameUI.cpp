#pragma once

#include "GameUI.h"

#include "Player.h"
#include "../game/menu.h"
#include "../game/stage.h"
#include "../game/endstage.h"
#include "../game/sceneManager.h"
#include "../game/vilege.h"
#include "Goblin.h"

iStrTex* hpIndicator;
iStrTex* mpIndicator;
iStrTex* staminaIndicator;
iStrTex* expIndicator;
iStrTex* nameIndicator;

iStrTex** skillIndicator;

iPopup* PopPlayerInventory;
Texture* methodPlayerHPIndicator(const char* str)
{
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(200, 50);

	setRGBA(1, 0, 0, 1);
	setStringSize(15);

	g->init(size);
	g->fillRect(0, 0, size.width * (hero->getHp() / hero->getMaxHp()), size.height);
	g->drawString(size.width / 2, size.height / 2, HCENTER | VCENTER, str);

	return g->getTexture();
}

Texture* methodPlayerMPIndicator(const char* str)
{
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(200, 50);

	setRGBA(0, 0, 1, 1);
	setStringSize(15);

	g->init(size);
	g->fillRect(0, 0, size.width * (hero->getMp() / hero->getMaxMP()), size.height);
	g->drawString(size.width / 2, size.height / 2, HCENTER | VCENTER, str);

	return g->getTexture();
}

Texture* methodPlayerStaminaIndicator(const char* str)
{
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(200, 50);

	setRGBA(1, 1, 0, 1);
	setStringSize(15);

	g->init(size);
	g->fillRect(0, 0, size.width * (hero->getStamina() / hero->getMaxStamina()), size.height);
	g->drawString(size.width / 2, size.height / 2, HCENTER | VCENTER, str);

	return g->getTexture();
}

Texture* methodPlayerExpIndicator(const char* str)
{
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(200, 50);

	setRGBA(0, 1, 0, 1);
	setStringSize(15);
	
	g->init(size);
	g->drawRect(0, 0, size.width, size.height);
	g->fillRect(0, 0, size.width * (hero->getExp() / 100.0f), size.height);
	g->drawString(size.width / 2, size.height / 2, HCENTER | VCENTER, str);

	return g->getTexture();
}

Texture* methodPlayerNameIndicator(const char* str)
{
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(200, 100);
	setStringSize(20);
	g->init(size);
	g->drawString(0, 0, TOP | LEFT, "Lv %s %s", str, hero->getName());

	return g->getTexture();
}

Texture* methodPlayerCooldownIndicator(const char* str)
{
	int lineNum;
	char** line = iString::getStringLine(str, lineNum);

	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(70, 70);
	setStringSize(17);
	g->init(size);
	g->fillRect(0, 0, size.width, size.height);
	if (atoi(line[0]) < 2)
	{
		float cooldown = atof(line[1]);
		g->drawString(size.width / 2, size.height / 2, HCENTER | VCENTER,
			"%s", cooldown ? str : "On!");
	}
	else
	{
		bool on = atoi(line[1]);
		g->drawString(size.width / 2, size.height / 2, HCENTER | VCENTER,
			"%s", on ? "Buff\nOn!" : "Buff\nOff!");
	}

	iString::freeStringLine(line, lineNum);

	return g->getTexture();
}

//----------------PopPlayerUI------------------------//

iPopup* PopPlayerUI;
iImage** PopPlayerUIImgs;
Texture* Poptex;
iPopup* PopMenuUI;

//const char* slotString[5] = { "Name", "HP", "MP", "Stamina", "Menu" };

const char* mapTitle[1] = { "Waterfront" };

Texture* methodTimeIndicator(const char* str);
Texture* methodKillIndicator(const char* str);
Texture* methodPlayerHPIndicator(const char* str);
Texture* methodPlayerMPIndicator(const char* str);
Texture* methodPlayerStaminaIndicator(const char* str);
Texture* methodPlayerExpIndicator(const char* str);
Texture* methodPlayerNameIndicator(const char* str);
Texture* methodPlayerCooldownIndicator(const char* str);

Texture* minimapFbo;

void createPopPlayerUI()
{
	iPopup* pop = new iPopup(iPopupStyleNone);

	iGraphics* g = iGraphics::instance();

	// Stage Title
	iSize size = iSizeMake(devSize.width, devSize.height); // 크기를 화면크기랑 동일하게 사용자의 화면을 그래도 덮는 UI Layer
	g->init(size);
	setStringRGBA(0, 0, 0, 1);
	setRGBA(1, 1, 1, 0);// alpha값은 0 투명한 사이즈의 화면크기의 상자를 만드는거니까
	g->fillRect(0, 0, devSize.width, devSize.height);
	g->drawString(devSize.width / 2, 10, HCENTER | VCENTER, "- Stage -");
	g->drawString(devSize.width / 2, 35, HCENTER | VCENTER, mapTitle[0]);
	//g->drawString(devSize.width / 2, 65, HCENTER | VCENTER, "KILL:");

	Texture* tex = g->getTexture();
	iImage* img = new iImage();
	img->addObject(tex);
	freeImage(tex);
	pop->addObject(img);

	// 미니맵
	tex = createTexture(devSize.width, devSize.height);
	tex->width *= 0.5;
	tex->potWidth *= 0.5;
	tex->height *= 0.5;
	tex->potHeight *= 0.5;
	img = new iImage();
	img->addObject(tex);
	freeImage(tex);
	img->leftRight = 2;
	img->position = iPointMake(devSize.width/2 +320, -60);
	pop->addObject(img);
	minimapFbo = tex;

	// Stage Menu
	PopPlayerUIImgs = (iImage**)malloc(sizeof(iImage*) * 7);

	// PopPlayerUIImgs[0]
	size = iSizeMake(200, 100);
	g->init(size);
	setRGBA(0, 0, 1, 1);
	g->fillRect(0, 0, size.width, size.height);
	setStringSize(30);
	g->drawString(size.width / 2, size.height / 2, HCENTER | VCENTER, "Menu");

	tex = g->getTexture();
	img = new iImage();
	img->addObject(tex);
	freeImage(tex);

	img->position = iPointMake(devSize.width - size.width, 10);
	pop->addObject(img);
	PopPlayerUIImgs[0] = img;

	// PopPlayerUIImgs[1] - Player Portrait
	tex = createImage("assets/stage/hero/Knight/KnightPortrait.png");
	img = new iImage();
	img->addObject(tex);
	freeImage(tex);
	img->position = iPointMake(0, 10);
	pop->addObject(img);
	PopPlayerUIImgs[1] = img;

	// Player Name Indicator
	iStrTex* st = new iStrTex(methodPlayerNameIndicator);
	st->setString("%d", hero->getLevel());
	img = new iImage();
	img->addObject(st->tex);
	//freeImage(st->tex);
	img->position = iPointMake(70, 15);
	pop->addObject(img);
	nameIndicator = st;/////////////////////////

	st = new iStrTex(methodPlayerHPIndicator);
	st->setString("HP : %.1f / %.1f", hero->getHp(), hero->getMaxHp());
	img = new iImage();
	img->addObject(st->tex);
	//freeImage(st->tex);
	img->position = iPointMake(0, 110);
	pop->addObject(img);
	PopPlayerUIImgs[2] = img;/////////////////////////
	hpIndicator = st;/////////////////////////

	st = new iStrTex(methodPlayerMPIndicator);
	st->setString("MP : %.1f / %.1f", hero->getMp(), hero->getMaxMP());
	img = new iImage();
	img->addObject(st->tex);
	//freeImage(st->tex);
	img->position = iPointMake(0, 160);
	pop->addObject(img);
	PopPlayerUIImgs[3] = img;
	mpIndicator = st;

	st = new iStrTex(methodPlayerStaminaIndicator);
	st->setString("Stamina : %.1f / %.1f", hero->getStamina(), hero->getMaxStamina());
	img = new iImage();
	img->addObject(st->tex);
	//freeImage(st->tex);
	img->position = iPointMake(0, 210);
	pop->addObject(img);
	PopPlayerUIImgs[4] = img;
	staminaIndicator = st;

	st = new iStrTex(methodPlayerExpIndicator);
	st->setString("Exp : %.1f, / 100", hero->getExp());
	img = new iImage();
	img->addObject(st->tex);
	//freeImage(st->tex);
	img->position = iPointMake(0, 260);
	pop->addObject(img);
	PopPlayerUIImgs[5] = img;
	expIndicator = st;

	//Inventory Btn
	size = iSizeMake(200, 100);
	g->init(size);
	setRGBA(0, 1, 0, 1);
	g->fillRect(0, 0, size.width, size.width);
	setStringSize(30);
	g->drawString(size.width / 2, size.height / 2, HCENTER | VCENTER, "Inventory");

	tex = g->getTexture();
	img = new iImage();
	img->addObject(tex);
	freeImage(tex);
	img->position = iPointMake(devSize.width - size.width, devSize.height - size.height);
	pop->addObject(img);
	PopPlayerUIImgs[6] = img;

	//SkillBar -BarBackground
	size = iSizeMake(500, 100);
	g->init(size);
	setRGBA(0, 0, 1, 1);
	g->fillRect(0, 0, size.width, size.height);

	tex = g->getTexture();
	img = new iImage();
	img->addObject(tex);
	freeImage(tex);
	img->position = iPointMake(devSize.width/2- size.width/2, devSize.height - size.height);
	pop->addObject(img);

	//SkillBar -BarBtn
	skillIndicator = (iStrTex**)malloc(sizeof(iStrTex*) * 3);
	setRGBA(1, 1, 1, 1);
	for (int i = 0; i < 3; i++)
	{
		st = new iStrTex(methodPlayerCooldownIndicator);
		st->setString("%d\n%d", i, i);
		img = new iImage();
		img->addObject(st->tex);
		//freeImage(st->tex);
		size = iSizeMake(st->tex->width, st->tex->height);
		img->position = iPointMake(devSize.width / 2 - size.width / 2 + 15 + (i * 100), devSize.height - size.height - 15);
		pop->addObject(img);
		skillIndicator[i] = st;
	}
	
	pop->openPosition = iPointZero;
	pop->closePosition = iPointZero;

	PopPlayerUI = pop;
	setRGBA(1, 1, 1, 1);

}

void freePopPlayerUI()
{
	delete PopPlayerUI;

	free(PopPlayerUIImgs);
	delete nameIndicator;
	delete hpIndicator;
	delete mpIndicator;
	delete staminaIndicator;
	delete expIndicator;
	for (int i = 0; i < 3; i++)
		delete skillIndicator[i];
	free(skillIndicator);
}

void drawPopPlayerUI(float dt)
{
	nameIndicator->setString("%d", hero->getLevel());
	hpIndicator->setString("HP : %.1f / %.1f", hero->getHp(), hero->getMaxHp());
	mpIndicator->setString("MP : %.1f / %.1f", hero->getMp(), hero->getMaxMP());
	staminaIndicator->setString("Stamina : %.1f / %.1f", hero->getStamina(), hero->getMaxStamina());

	skillIndicator[0]->setString("%d\n%1.0f", 0, hero->_CoolDown_SK1 - hero->CoolDown_SK1);
	skillIndicator[1]->setString("%d\n%1.0f", 1, hero->_CoolDown_SK2 - hero->CoolDown_SK2);
	skillIndicator[2]->setString("%d\n%d", 2, hero->imgBuff->animation);

	expIndicator->setString("%f", (hero->getExp()));

	PopPlayerUI->paint(dt);
}

iPopup* PopQuitAnswerUI;
bool keyPopPlayerUI(iKeyState stat, iPoint point)
{

	int i, j = -1;

	switch (stat)
	{
	case iKeyState::iKeyStateBegan:
		i = PopPlayerUI->selected;

		if (i == -1)
			break;

		else if (i == 0)
		{
			printf("selected = %d\n", i);

			if (PopMenuUI->bShow == false)
				showPopMenuUI(true);

			else
				showPopMenuUI(false);
		}

		else if (i == 5)
		{
			if (PopPlayerInventory->bShow == false)
				showPopPlayerInventory(true);

			else
				showPopPlayerInventory(false);
		}

		else
			printf("seletecd = %d\n", i);
		break;

	case iKeyState::iKeyStateMoved:

		for (i = 0; i < 6; i++)
		{
			if (containPoint(point, PopPlayerUIImgs[i]->touchRect(PopPlayerUI->closePosition)))
			{
				j = i;
				break;
			}
		}
		PopPlayerUI->selected = j;
		break;

	case iKeyState::iKeyStateEnded:

		break;

	}

	return true;
}

void showPopPlayerUI(bool show)
{
	PopPlayerUI->show(show);
}



//--------------PopMenuUI---------------------/

//iPopup* PopMenuUI; PlayerUI 위에 선언해놨음.
iImage** PopMenuUIImgs;

const char* btnString[3] = { "Rusume Game", "Settings", "Game Quit" };

void createPopMenuUI()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(500, 500);

	PopMenuUIImgs = (iImage**)malloc(sizeof(iImage*) * 3);

	// Background //
	{
		iImage* img = new iImage();
		Texture* tex;
		g->init(size);
		setStringRGBA(0, 0, 0, 1);
		setRGBA(1, 0, 1, 1);
		g->fillRect(0, 0, size.width, size.height);

		tex = g->getTexture();
		img->addObject(tex);
		freeImage(tex);
		img->position = iPointMake(0, 0);

		pop->addObject(img);
	}

	// buttons
	{
		setRGBA(0, 1, 1, 1);
		setStringRGBA(0, 0, 0, 1);
		setStringSize(20);

		iSize btnSize = iSizeMake(300, 30);

		for (int i = 0; i < 3; i++)
		{
			Texture* tex;
			iImage* btnImg = new iImage();

			g->init(btnSize);
			g->fillRect(0, 0, btnSize.width, btnSize.height);
			g->drawString(btnSize.width / 2, btnSize.height / 2, HCENTER | VCENTER, btnString[i]);

			tex = g->getTexture();
			btnImg->addObject(tex);
			freeImage(tex);

			btnImg->position = iPointMake((size.width - btnSize.width) / 2, i * 100 + 15);

			PopMenuUIImgs[i] = btnImg;
			pop->addObject(btnImg);

		}

	}

	// 메뉴창에 간단하게 게임 설명(목표) 넣는 부분

	pop->openPosition = iPointMake((devSize.width - size.width) / 2, (devSize.height - size.height) / 2);
	pop->closePosition = pop->openPosition;

	setRGBA(1, 1, 1, 1);

	PopMenuUI = pop;

}

void freePopMenuUI()
{
	delete PopMenuUI;

}

void drawPopMenuUI(float dt)
{
	PopMenuUI->paint(dt);
}

bool keyPopMenuUI(iKeyState stat, iPoint point)
{
	if (PopMenuUI->bShow == false)
		return false;

	if (PopMenuUI->stat != iPopupStatProc)
		return true;

	int i, j = -1;

	switch (stat)
	{
	case iKeyState::iKeyStateBegan:
	{
		i = PopMenuUI->selected;

		if (i == -1)
			break;

		else if (i == 0)
		{
			PopMenuUI->show(false);
		}

		else if (i == 1)
		{

		}

		else if (i == 2)
		{
			PopQuitAnswerUI->show(true);
			//showPopQuitAnswerUI(true);
		printf("seletecd = %d\n", i);
		}

		break;
	}

	case iKeyState::iKeyStateMoved:
	{

		for (i = 0; i < 3; i++)
		{
			if (containPoint(point, PopMenuUIImgs[i]->touchRect(PopMenuUI->closePosition)))
			{
				j = i;
				break;
			}
		}
		PopMenuUI->selected = j;

		break;
	}
	case iKeyState::iKeyStateEnded:
	{
		break;
	}

	}

	return true;
}

void showPopMenuUI(bool show)
{
	PopMenuUI->show(show);
}


//----------------------PopQuitAnswerUI------------------------//

//iPopup* PopQuitAnswerUI;
iImage** PopQuitAnswerUIBtn;
// 0 : yes,  1 : no
const char* btnUISlot[2] = { "Okay", "No" };
void createPopQuitAnswerUI()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(500, 300);

	PopQuitAnswerUIBtn = (iImage**)malloc(sizeof(iImage*) * 2); // 0 : yes , 1 : no

	setStringBorder(0);
	setStringBorderRGBA(0, 0, 0, 1);
	setStringRGBA(0, 0, 0, 1);
	setStringSize(50);



	{ // background
		igImage* ig = g->createIgImage("assets/menu/popBg.png");
		size = iSizeMake(g->getIgImageWidth(ig) * 2.5, g->getIgImageHeight(ig) * 2.5);
		g->init(size);
		g->drawImage(ig, 0, 0, 2.5, 2.5, TOP | LEFT);
		g->freeIgImage(ig);
		g->drawString(size.width / 2, size.height / 2 - 175, VCENTER | HCENTER, "Do you want exit?");
		Texture* bgTex;

		bgTex = g->getTexture();

		iImage* bgImg = new iImage();
		bgImg->position = iPointMake(devSize.width / 2, devSize.height / 2);

		bgImg->addObject(bgTex);
		freeImage(bgTex);

		pop->addObject(bgImg);

	}

	for (int i = 0; i < 2; i++)
	{
		iImage* answerBtn = new iImage();
		Texture* btnTex;

		for (int j = 0; j < 2; j++)
		{
			if (j == 0) // btnOff
			{
				setRGBA(1, 1, 1, 1);
				setStringSize(30);
				igImage* answerBtn = g->createIgImage("assets/menu/BTN0.png");
				iSize btnSize = iSizeMake(g->getIgImageWidth(answerBtn), g->getIgImageHeight(answerBtn));
				g->init(btnSize);
				g->drawImage(answerBtn, 0, 0, 1, 1, TOP | LEFT);
				g->freeIgImage(answerBtn);
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnUISlot[i]);
				btnTex = g->getTexture();
			}

			else // btnOn
			{
				setRGBA(1, 0, 0, 1);
				setStringSize(30);
				igImage* answerBtn = g->createIgImage("assets/menu/BTN0.png");
				iSize btnSize = iSizeMake(g->getIgImageWidth(answerBtn), g->getIgImageHeight(answerBtn));
				g->init(btnSize);
				g->drawImage(answerBtn, 0, 0, 1, 1, TOP | LEFT);
				g->freeIgImage(answerBtn);
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnUISlot[i]);
				btnTex = g->getTexture();
			}

			answerBtn->addObject(btnTex);
			answerBtn->position = iPointMake(devSize.width / 2 * (i + 1) + 150, size.height + 10);
			freeImage(btnTex);
		}

		pop->addObject(answerBtn);

		PopQuitAnswerUIBtn[i] = answerBtn;

	}

	pop->openPosition = iPointMake(devSize.width / 2 - size.width - 100, devSize.height / 2 - size.height);
	pop->closePosition = pop->openPosition;
	PopQuitAnswerUI = pop;

}

void freePopQuitAnswerUI()
{
	delete PopQuitAnswerUI;
	free(PopQuitAnswerUIBtn);
}

void drawPopQuitAnswerUI(float dt)
{
	PopQuitAnswerUI->paint(dt);
}

bool keyPopQuitAnswerUI(iKeyState stat, iPoint point)
{
	if (PopQuitAnswerUI->bShow == false)
		return false;

	if (PopQuitAnswerUI->stat != iPopupStatProc)
		return true;

	int i, j = -1;

	switch (stat)
	{
	case iKeyState::iKeyStateBegan:
	{
		i = PopQuitAnswerUI->selected;

		if (i == -1)
			break;

		if (i == 0)
		{
			extern bool runWnd;
			runWnd = false;

		}
		else if (i == 1)
		{
			PopQuitAnswerUI->show(false);
		}
		break;
	}

	case iKeyState::iKeyStateMoved:
	{
		for (i = 0; i < 2; i++)
		{
			if (containPoint(point, PopQuitAnswerUIBtn[i]->touchRect(PopQuitAnswerUI->closePosition)))
			{
				j = i;
				break;
			}
		}
		PopQuitAnswerUI->selected = j;
		break;
	}

	case iKeyState::iKeyStateEnded:
		break;
	}

	return true;
}

void showPopQuitAnswerUI(bool show)
{
	PopQuitAnswerUI->show(show);
}



//------------PopGameOverUI---------------//

iPopup* PopGameOver;
iImage** GameOverBtn;
const char* btnStr[2] = { "MainMenu", "Game Quit" };

void createPopGameOverUI()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(devSize.width, devSize.height);
	setRGBA(1, 0, 0, 1);
	fillRect(0, 0, devSize.width, devSize.height);

	// gameOverTitle
	{
		setStringSize(30);
		setRGBA(1, 0, 0, 1);
		iSize titleSize = iSizeMake(devSize.width, devSize.height);
		g->init(titleSize);
		g->fillRect(0, 0, devSize.width, devSize.height);
		g->drawString(titleSize.width / 2, titleSize.height / 2, HCENTER | VCENTER, "You die......!");
		Texture* overTitleTex;
		overTitleTex = g->getTexture();

		iImage* overTitle = new iImage();
		overTitle->addObject(overTitleTex);
		overTitle->position = iPointMake(devSize.width / 2, devSize.height / 2);

		freeImage(overTitleTex);

		pop->addObject(overTitle);
	}

	GameOverBtn = (iImage**)malloc(sizeof(iImage*) * 2); // 0 : 메인메뉴 1 : 게임종료
	for (int i = 0; i < 2; i++)
	{
		iImage* answerBtn = new iImage();
		Texture* btnTex;

		for (int j = 0; j < 2; j++)
		{
			if (j == 0) // off
			{
				setRGBA(1, 1, 1, 1);
				setStringSize(15);
				igImage* answerBtn = g->createIgImage("assets/menu/BTN0.png");
				iSize btnSize = iSizeMake(g->getIgImageWidth(answerBtn), g->getIgImageHeight(answerBtn));
				g->init(btnSize);
				g->drawImage(answerBtn, 0, 0, 1, 1, TOP | LEFT);
				g->freeIgImage(answerBtn);
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnStr[i]);
				btnTex = g->getTexture();
			}

			else // on
			{
				setRGBA(1, 0, 0, 1);
				setStringSize(15);
				igImage* answerBtn = g->createIgImage("assets/menu/BTN0.png");
				iSize btnSize = iSizeMake(g->getIgImageWidth(answerBtn), g->getIgImageHeight(answerBtn));
				g->init(btnSize);
				g->drawImage(answerBtn, 0, 0, 1, 1, TOP | LEFT);
				g->freeIgImage(answerBtn);
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnStr[i]);
				btnTex = g->getTexture();
			}

			answerBtn->addObject(btnTex);
			answerBtn->position = iPointMake(devSize.width / 2 * (i + 1) + 150, size.height + 10);
			freeImage(btnTex);
		}

		pop->addObject(answerBtn);

		GameOverBtn[i] = answerBtn;
	}

	pop->openPosition = iPointMake(devSize.width / 2 - size.width, devSize.height / 2 - size.height);
	pop->closePosition = pop->openPosition;

	PopGameOver = pop;
}

void freePopGameOverUI()
{
	delete PopGameOver;
	free(GameOverBtn);
}

void drawPopGameOverUI(float dt)
{
	PopGameOver->paint(dt);
}

bool keyPopGameOverUI(iKeyState stat, iPoint point)
{
	if (PopGameOver->bShow == false)
		return false;

	if (PopGameOver->stat != iPopupStatProc)
		return true;

	int i, j = -1;

	switch (stat)
	{
	case iKeyState::iKeyStateBegan:
	{
		i = PopGameOver->selected;

		if (i == -1)
			break;

		if (i == 0)
		{
			switch (gameState)
			{
			case gs_stage:
				setLoading(gs_menu, freeStage, loadMenu);
				break;

			case gs_endStage:
				setLoading(gs_menu, freeEndStage, loadMenu);
				break;

			}
		}

		else if (i == 1)
		{
			extern bool runWnd;
			runWnd = false;
		}
		break;
	}

	case iKeyState::iKeyStateMoved:
	{
		for (i = 0; i < 2; i++)
		{
			if (containPoint(point, GameOverBtn[i]->touchRect(PopGameOver->closePosition)))
			{
				j = i;
				break;
			}
		}

		PopGameOver->selected = j;
		break;
	}

	case iKeyState::iKeyStateEnded:
		break;

	}

	return true;
}

void showPopGameOverUI(bool show)
{
	PopGameOver->show(show);
}

//-----------------PopStageNPCMenuUI---------------------//

iPopup* PopStageNPCMenuUI;
iImage** PopStageNPCMenuUIImgs;

const char* StageNPCStr[2] = { "Yes", "No" };

void createPopStageNPCMenuUI()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(700, 300);

	PopStageNPCMenuUIImgs = (iImage**)malloc(sizeof(iImage*) * 2);

	setStringBorder(0);
	setStringBorderRGBA(0, 0, 0, 1);
	setStringRGBA(0, 0, 0, 1);
	setStringSize(30);


	// Background //
	{
		iImage* img = new iImage();
		Texture* tex;
		setRGBA(0, 1, 1, 1);
		g->init(size);
		g->fillRect(0, 0, size.width, size.height);
		g->drawString(size.width / 2, 30, HCENTER | VCENTER, "Would you like to enter the village?");

		tex = g->getTexture();
		img->addObject(tex);
		freeImage(tex);
		img->position = iPointMake(0, 0);

		pop->addObject(img);
	}

	// button //
	{
		setRGBA(1, 0, 0, 1);
		setStringSize(15);

		iSize btnSize = iSizeMake(150, 30);

		for (int i = 0; i < 2; i++)
		{
			iImage* answerBtn = new iImage();
			Texture* btnTex;

			for (int j = 0; j < 2; j++)
			{
				if (j == 0) // btnoff
				{
					setRGBA(0, 1, 0, 1);
					g->init(btnSize);
					g->fillRect(0, 0, btnSize.width, btnSize.height);
					g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, StageNPCStr[i]);
					btnTex = g->getTexture();
				}

				else // btnon
				{
					setRGBA(1, 0, 0, 1);
					g->init(btnSize);
					g->fillRect(0, 0, btnSize.width, btnSize.height);
					g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, StageNPCStr[i]);
					btnTex = g->getTexture();
				}
				answerBtn->addObject(btnTex);
				answerBtn->position = iPointMake(200 * i + 150, size.height / 2 + 20);
				freeImage(btnTex);
			}

			pop->addObject(answerBtn);

			PopStageNPCMenuUIImgs[i] = answerBtn;

		}

	}


	pop->openPosition = iPointMake(devSize.width / 2 - size.width / 2, devSize.height / 2 - size.height / 2);
	pop->closePosition = pop->openPosition;


	PopStageNPCMenuUI = pop;
}

void freePopStageNPCMenuUI()
{

	free(PopStageNPCMenuUIImgs);

	// iPopup delete시 안에 있는 Img들 다 메모리 해제함

	delete PopStageNPCMenuUI;

}

void drawPopStageNPCMenuUI(float dt)
{
	PopStageNPCMenuUI->paint(dt);
}

bool keyPopStageNPCMenuUI(iKeyState stat, iPoint point)
{
	if (PopStageNPCMenuUI->bShow == false)
		return false;

	if (PopStageNPCMenuUI->stat != iPopupStatProc)
		return true;

	int i, j = -1;

	switch (stat)
	{
	case iKeyState::iKeyStateBegan:
	{
		i = PopStageNPCMenuUI->selected;

		if (i == -1)
			break;

		if (i == 0)
		{
			
			setLoading(gs_villege, freeEndStage, loadVillege);

		}
		else if (i == 1)
		{
			
			PopStageNPCMenuUI->show(false);
		}
		break;
	}
	case iKeyState::iKeyStateMoved:
	{
		for (i = 0; i < 2; i++)
		{
			if (containPoint(point, PopStageNPCMenuUIImgs[i]->touchRect(PopStageNPCMenuUI->closePosition)))
			{
				j = i;
				break;
			}
		}
		PopStageNPCMenuUI->selected = j;
		break;
	}
	}
	return true;
}

void showPopStageNPCMenuUI(bool show)
{
	PopStageNPCMenuUI->show(show);
}

//----------------PopPlayerInventory------------------//
//iPopup* PopPlayerInventory; 맨위에 선언함
iImage** PopPlayerInventoryImgs;

iStrTex* moneyIndicator;
Texture* methodPlayerMoneyIndicator(const char* str)
{
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(100, 100);


	setRGBA(0, 0, 1, 1);
	setStringSize(20);
	g->init(size);
	g->fillRect(0, 0, size.width, size.height);
	g->drawString(size.width / 2, 10, HCENTER | VCENTER, "Money");
	g->drawString(size.width / 2, 40, HCENTER | VCENTER, "%s", str);


	return g->getTexture();
}

void createPopPlayerInventory()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iGraphics* g = iGraphics::instance();

	iSize bgSize = iSizeMake(700, 300);

	//Inventory background
	setRGBA(1, 1, 1, 1);
	setStringSize(20);
	g->init(bgSize);
	g->fillRect(0, 0, bgSize.width, bgSize.height);
	g->drawString(bgSize.width / 2, 20, HCENTER | VCENTER, "%s Inventory", hero->getName());
	Texture* tex = g->getTexture();
	iImage* img = new iImage();
	img->addObject(tex);
	freeImage(tex);
	img->position = iPointZero;
	pop->addObject(img);	

	PopPlayerInventoryImgs = (iImage**)malloc(sizeof(iImage*) * 20); // 임시로 20개 만듬

	// Equitment - PopPlayerInventoryImgs[0 ~ 3]
	iSize size = iSizeMake(250, 250);
	g->init(size);

	setRGBA(1, 0, 0, 1);
	g->fillRect(0, 0, size.width, size.height);
	g->drawString(size.width / 2, 10, HCENTER|VCENTER, "Enquitment");

	tex = g->getTexture();
	img = new iImage();
	img->addObject(tex);
	freeImage(tex);
	img->position = iPointMake(10, 35);
	pop->addObject(img);

	iSize rectSize = iSizeMake(64, 64);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			g->init(rectSize);

			setRGBA(1, 1, 0, 1);
			g->fillRect(0, 0, rectSize.width, rectSize.height * (i + 1));

			tex = g->getTexture();
			img = new iImage();
			img->addObject(tex);
			freeImage(tex);
			img->position = iPointMake(size.width / 2 - rectSize.width + (100 * j), size.height / 2 - rectSize.height/2 + (100 * i));
			pop->addObject(img);
			PopPlayerInventoryImgs[2 * i + j] = img;////////////////////
		}
	}
	// bags - PopPlayerInventoryImgs[4 ~ 7]
	size = iSizeMake(250, 250);
	g->init(size);

	setRGBA(0, 1, 0, 1);
	g->fillRect(0, 0, size.width, size.height);
	g->drawString(size.width / 2, 10, HCENTER | VCENTER, "Bags");

	tex = g->getTexture();
	img = new iImage();
	img->addObject(tex);
	freeImage(tex);
	img->position = iPointMake(bgSize.width - size.width - 10, 35);
	pop->addObject(img);

	rectSize = iSizeMake(64, 64);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			g->init(rectSize);

			setRGBA(1, 1, 1, 1);
			g->fillRect(0, 0, rectSize.width, rectSize.height * (i + 1));

			tex = g->getTexture();
			img = new iImage();
			img->addObject(tex);
			freeImage(tex);
			img->position = iPointMake(size.width / 2 - rectSize.width + (100 * j)+ 420, size.height / 2 - rectSize.height / 2 + (100 * i));
			pop->addObject(img);
			PopPlayerInventoryImgs[4 + 2 * i + j] = img;////////////////////
		}
	}

	// Money
	iStrTex* st = new iStrTex(methodPlayerMoneyIndicator);
	st->setString("%d", hero->money);
	img = new iImage();
	img->addObject(st->tex);
	//freeImage(st->tex);
	img->position = iPointMake(bgSize.width / 2 - st->tex->width / 2, 35);
	pop->addObject(img);
	moneyIndicator = st;
	
	pop->openPosition = iPointMake(devSize.width / 2 - bgSize.width / 2, devSize.height / 2 - bgSize.height / 2);
	pop->closePosition = pop->openPosition;
	PopPlayerInventory = pop;
}

void freePopPlayerInventory()
{
	delete PopPlayerInventory;
	free(PopPlayerInventoryImgs);
	delete moneyIndicator;
}

void drawPopPlayerInventory(float dt)
{
	moneyIndicator->setString("%d", hero->money);

	PopPlayerInventory->paint(dt);
}

bool keyPopPlayerInventory(iKeyState stat, iPoint point)
{
	return true;
}

void showPopPlayerInventory(bool show)
{
	PopPlayerInventory->show(show);
}

Texture* methodStDamage(const char* str)
{
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(100, 20);

	setRGBA(1, 1, 1, 0);
	g->init(size);
	g->fillRect(0, 0, size.width, size.height);

	setRGBA(1, 1, 1, 1);
	setStringSize(20);
	setStringRGBA(1, 0, 0, 1);
	g->drawString(size.width / 2, size.height / 2, HCENTER | VCENTER, str);


	return g->getTexture();

}

