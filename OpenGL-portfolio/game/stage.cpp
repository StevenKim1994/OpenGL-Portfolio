#pragma once
#include "stage.h"
#include "stageTileInfo.h"
#include "Monster.h"
#include "Player.h"
#include "Orc.h"
#include "sceneManager.h"

#include "GameUI.h"
#include "endstage.h"


#define ON_HITBOX 0

Player* hero;
MapTile* maptile;
iPoint offMt;
iPoint vp;

Monster** orcs;
//Orc* orc;




int _orcNum = orc_Num;
int orcNum = _orcNum;

Texture* tileset[1521];
Texture* map;
Texture* texFboStage;
Texture* playerPortrait;
iShortestPath* sp;
bool mouseMove = false;

iStrTex* killIndicator;
iStrTex* timeIndicator;
iStrTex* hpIndicator;
iStrTex* mpIndicator;
iStrTex* staminaIndicator;




float gameTime = 0;
float _gameTime = 100000000000;

float logoDt = 0.0;
Texture* stageLogo;



int tiles[MapTileNumX * MapTileNumY] =
{
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,77,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,99,99,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
44,44,44,44,44,44,44,44,44,99,99,99,44,44,99,99,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
44,44,44,44,44,44,44,44,44,99,99,99,44,44,99,99,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
44,44,44,44,44,44,44,44,44,44,44,44,44,44,99,99,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
44,44,44,44,44,44,44,44,44,44,44,44,44,44,99,99,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
44,44,44,44,44,44,44,44,44,44,44,44,44,44,99,99,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
44,44,44,44,44,44,44,44,44,44,44,44,44,44,99,99,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
}; // 01 : canMove
   // 99 : canNotMove
   // 44 : deadZone



Texture* methodTimeIndicator(const char* str)
{
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(500, 50);

	setRGBA(1, 1, 1, 0);
	g->init(size);
	g->fillRect(0, 0, size.width, size.height);

	setRGBA(1, 1, 1, 1);
	setStringSize(50);
	setStringRGBA(1, 1, 0, 1);
	g->drawString(size.width / 2 - 50, size.height / 2, HCENTER | VCENTER, str);


	return g->getTexture();
}

Texture* methodKillIndicator(const char* str)
{
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(100, 50);

	setRGBA(1, 1, 1, 0);
	g->init(size);
	g->fillRect(0, 0, size.width, size.height);

	setRGBA(1, 1, 1, 1);
	setStringSize(50);
	setStringRGBA(1, 1, 0, 1);
	g->drawString(size.width / 2 - 50, size.height / 2, HCENTER | VCENTER, str);


	return g->getTexture();


}

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

	setRGBA(0,0,1,1);
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


void loadStage()
{
	playerPortrait = createImage("assets/stage/hero/Knight/KnightPortrait.png");
	texFboStage = createTexture(devSize.width, devSize.height);

	iGraphics* g = iGraphics::instance();
	setRGBA(0, 0, 0, 0);
	iSize logoSize = iSizeMake(500, 70);
	setRGBA(1, 1, 1, 0);
	g->init(logoSize);
	g->fillRect(0, 0, logoSize.width, logoSize.height);

	setStringSize(70);
	setStringRGBA(0, 0, 0, 1);
	g->drawString(logoSize.width/2, logoSize.height/2,HCENTER|VCENTER,"Waterfront");
	stageLogo = g->getTexture();


	
	setStringSize(30);
	setRGBA(1, 1, 1, 1);

	for (int i = 0; i < 1520; i++)
	{
#if 0
		iGraphics* g = iGraphics::instance();
		igImage* ig = g->createIgImage("assets/stage/tileset/mapsplit/tile%03d.png", i);
		iSize igSize = iSizeMake(g->getIgImageWidth(ig) * 2.0, g->getIgImageHeight(ig) * 2.0);
		g->init(igSize);
		g->drawImage(ig, 0, 0, 2.0, 2.0, TOP | LEFT);
		tileset[i] = g->getTexture(); // GDI+ 사용 확대 이러면 사이 간격이 생김
#else
		Texture* tex = createImage("assets/stage/tileset/mapsplit/tile%03d.png", i);
		tex->width *= 2;
		tex->height *= 2;
		tex->potWidth *= 2;
		tex->potHeight *= 2;
		tileset[i] = tex;
#endif
	}
	
	setRGBA(1, 1, 1, 1);


	int i, num = MapTileNumX * MapTileNumY;
	maptile = (MapTile*)malloc(sizeof(MapTile) * num);
	for (i = 0; i < num; i++)
	{
		MapTile* t = &maptile[i];
		t->attr = tiles[i];
		//t->imgIndex;
	}

	hero = new Player(); // 플레이어 캐릭터 생성

	{
		hero->setSize(iSizeMake(PlayerWidth, PlayerHeight));
		hero->setMovement(MapCharMovement);
		hero->setPosition(iPointMake(MapTileWidth * 18, MapTileHeight * 17));
		
		// hero name Initialize
		hero->setName("Steven");
		hero->alive = true;

		// hero HP Initialize
		hero->setMaxHp(100.0);
		hero->setHP(100.00);

		// hero MP Initialize
		hero->setMaxMp(100.0);
		hero->setMP(100.0);

		// hero Stamina Initialize
		hero->setMaxStamina(100.0);
		hero->setStamina(100.0);
	

	}

	// camera positioning Initialize
	{
		offMt = hero->getPosition();
		offMt = iPointMake(0, -2000 + 500);
	}


	
	orcs = (Monster**)malloc(sizeof(Monster) * orc_Num);
	for (int i = 0; i < orc_Num; i++) // 맵에 오크 생성
	{
		Orc* orc = new Orc(i);
		orc->setPosition(iPointMake(MapTileWidth * 30 + (i * MapTileWidth+30), MapTileHeight*17));
		orc->alive = true;
		orcs[i] = orc;
	}
	

	sp = new iShortestPath();
	sp->init(tiles, MapTileNumX, MapTileNumY);

	killIndicator = new iStrTex(methodKillIndicator);
	killIndicator->setString("%d", hero->kill);
	
	//timeIndicator = new iStrTex(methodTimeIndicator);
	//timeIndicator->setString("TIME : %0.2f", gameTime);

	hpIndicator = new iStrTex(methodPlayerHPIndicator);
	hpIndicator->setString("HP : %.1f / %.1f", hero->getHp(), hero->getMaxHp());

	mpIndicator = new iStrTex(methodPlayerMPIndicator);
	mpIndicator->setString("MP : %.1f / %.1f", hero->getMp(), hero->getMaxMP());

	staminaIndicator = new iStrTex(methodPlayerStaminaIndicator);
	staminaIndicator->setString("Stamina : %.1f / %.1f", hero->getStamina(), hero->getMaxStamina());

	createPopPlayerUI();
	createPopMenuUI();
	createPopQuitAnswerUI();
	createPopGameOverUI();
	loadNumber();
	
}

void freeStage()
{
	freeImage(texFboStage);
	free(maptile);
	free(orcs);

	delete sp;
//
//hero는 다음Stage에서 사용되므로 delete 하지 않음!
//UI는 여기서 생성되고 게임오버할떄 까지 계속쓰이므로 게임오버할떄 지운다

}

void drawStage(float dt)
{
	fbo->bind(texFboStage);
	drawMapTile(dt);
	drawOrc(dt);
	drawHero(dt);

#if _DEBUG
	debugHitbox(dt);
#endif
	fbo->unbind();
	showCamera(texFboStage, dt);

	//gameTime += dt;
	//timeIndicator->setString("TIME : %0.2f",gameTime);
	drawNumber(dt, offMt);

	drawPopPlayerUI(dt);
	drawPopMenuUI(dt);
	drawPopQuitAnswerUI(dt);
	
	drawPopGameOverUI(dt);
	
	if (hero->alive == false) // 플레이어가 죽으면 
	{
		printf("Player is Dead\n");
		showPopGameOverUI(true);
	}

	static bool nextStageIn = false;
	if (hero->getPosition().x >= 2512 && hero->getPosition().y >= 494 && nextStageIn ==false)
	{
		nextStageIn = true;
		printf("nextStageLoad!!!\n");
		setLoading(gs_endStage, freeStage, loadEndStage); // 다음 씬으로! loadendStage()
	}

	{ // logoFadeInOut
		if (logoDt < _logoDt)
		{
			float r = 1.0 * _cos(90 * logoDt / _logoDt);
			setRGBA(1, 1, 1, r);
			drawImage(stageLogo, devSize.width / 2, devSize.height / 2 - 230, HCENTER | VCENTER);
			logoDt += 0.01;

			if (logoDt > _logoDt)
			{
				showPopPlayerUI(true);
			}
		}
	}

	if (hero->getStamina() != hero->getMaxStamina())
	{
		hero->setStamina(hero->getStamina()+ 0.1f);
		staminaIndicator->setString("%f", (hero->getStamina()));

		if (hero->getStamina() > hero->getMaxStamina())
			hero->setStamina(hero->getMaxStamina());
	}
}

void keyStage(iKeyState stat, iPoint point)
{
	
	if (keyPopGameOverUI(stat, point))
		return;


	if(keyPopQuitAnswerUI(stat, point))
		return;

	if (keyPopMenuUI(stat, point))
		return;
	
	keyPopPlayerUI(stat, point);
		

		
	if (stat == iKeyStateBegan)
	{
		printf("!!\n");
		
		
		int sx = hero->getPosition().x;
		sx /= MapTileWidth;

		int sy = hero->getPosition().y;
		sy /= MapTileHeight;

		int ex = point.x - offMt.x;
		ex /= MapTileWidth;

		int ey = point.y - offMt.y;
		ey /= MapTileHeight;
		

		
		if (sy != ey) // 횡스크롤 게임이므로 최단경로 고려할떄 같은 가로위치일떄만 고려함
			return;

		sp->dijkstra(sy * MapTileNumX + sx, ey * MapTileNumX + ex, hero->path, hero->pathNum);
		
		sp->removeDuplicate(hero->path, hero->pathNum);
		hero->setTargetPosition(hero->getPosition());
		hero->pathIndex = 1;

		mouseMove = true;
	}


}
