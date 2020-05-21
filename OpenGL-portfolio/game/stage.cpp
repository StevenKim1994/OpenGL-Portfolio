#pragma once
#include "stage.h"
#include "stageTileInfo.h"
#include "Monster.h"
#include "Player.h"
#include "Orc.h"
#include "sceneManager.h"

#include "GameUI.h"
#include "menu.h"


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







#define ON_HITBOX 0

Player* hero;
MapTile* maptile;
iPoint offMt;
iPoint vp;

Monster** orcs;
//Orc* orc;
Texture* bgTex; // bacckground Image

#define orc_Num 10

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

float gameTime = 0;
float _gameTime = 100000000000;
#define _logoDt 1.0f
float logoDt = 0.0;
Texture* stageLogo;

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
	
	setRGBA(1,1, 1, 1);
	setStringSize(50);
	setStringRGBA(1, 1, 0, 1);
	g->drawString(size.width / 2 - 50, size.height / 2, HCENTER|VCENTER, str);


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
		hero->setHP(90.0);

		// hero MP Initialize
		hero->setMaxMp(100.0);
		hero->setMP(30.0);

		// hero Stamina Initialize
		hero->setMaxStamina(100.0);
		hero->setStamina(20.0);
	

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
	
	timeIndicator = new iStrTex(methodTimeIndicator);
	timeIndicator->setString("TIME : %0.2f", gameTime);


	createPopPlayerUI();
	createPopMenuUI();
	createPopQuitAnswerUI();
	createPopGameOverUI();
	loadNumber();
	
}

void freeStage()
{
	//hero는 다음Stage에서 사용되므로 delete 하지 않음!
	freeImage(texFboStage);

	free(maptile);
	

	free(orcs);

	delete sp;

	freePopPlayerUI();
	freePopMenuUI();
	freePopQuitAnswerUI();
	freePopGameOverUI();
	freeNumber();
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

	gameTime += dt;
	timeIndicator->setString("TIME : %0.2f",gameTime);
	drawNumber(dt, offMt);

	drawPopPlayerUI(dt);
	drawPopMenuUI(dt);
	drawPopQuitAnswerUI(dt);
	
	drawPopGameOverUI(dt);
	
	if (hero->alive == false) // 플레이어가 죽으면 
	{
		printf("죽음!!!\n");
		showPopGameOverUI(true);
	}

	static bool nextStageIn = false;
	if (hero->getPosition().x >= 2512 && hero->getPosition().y >= 494 && nextStageIn ==false)
	{
		nextStageIn = true;
		printf("nextStageLoad!!!\n");
		setLoading(gs_menu, freeStage, loadMenu); // 다음 씬으로! loadendStage()
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
		

		printf("sx : %d sy : %d  ex : %d ey : %d\n", sx, sy, ex, ey);
		printf("begin :%d dest : %d\n", sy * MapTileNumX+ sx, ey * MapTileNumX + ex);
		
		
		if (sy != ey) // 횡스크롤 게임이므로 최단경로 고려할떄 같은 가로위치일떄만 고려함
			return;

		sp->dijkstra(sy * MapTileNumX + sx, ey * MapTileNumX + ex, hero->path, hero->pathNum);
		

		for(int i = 0 ; i < hero->pathNum; i++)
			printf("중복제거전! %d ,%d\n", i, hero->path[i]);
		sp->removeDuplicate(hero->path, hero->pathNum);
		hero->setTargetPosition(hero->getPosition());
		hero->pathIndex = 1;

		for (int i = 0; i < hero->pathNum; i++)
			printf("%d ,%d\n", i, hero->path[i]);
		mouseMove = true;
	}


}


void drawMapTile(float dt)
{
	int i, num = MapTileNumX * MapTileNumY;

	setRGBA(1, 1, 1, 1);
	{ // MapTilePaint

		for (i = 0; i < num; i++) // layer 0
		{
			MapTile* t = &maptile[i];

			float x = offMt.x + MapTileWidth * (i % MapTileNumX);
			float y = offMt.y + MapTileHeight * (i / MapTileNumX);

			if (i > 879)
			{
				setRGBA(1, 1, 1, 1);
				drawImage(tileset[i - 880], x, y, TOP | LEFT);
			}
			else
			{
				setRGBA(0.63137, 0.94901, 0.92549, 1);
				fillRect(x, y, 32, 32);
			}

#if _DEBUG // tileHitbox
			switch (t->attr)
			{
				//case canMove: break;
				//case canNotMove: setRGBA(0, 1, 1, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
				//case deadZone:	setRGBA(1, 0, 0, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
				//case nextStagePortal: setRGBA(0, 1, 1, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
			}
#endif

		}

	}

}

void drawHero(float dt)
{
	uint32 keyStat = 0;
	uint32 keyDown = 0;

	iPoint movement = iPointMake(0, 1) * powGravity * dt;
	hero->applyJump(movement, dt);

	if (getKeyDown() & keyboard_space) // 윗점프
	{

		hero->jump();
		if (hero->behave != PlayerBehave_meleeAttack)
		{
			keyStat = getKeyStat();
			keyDown = getKeyDown();
		}
		iPoint v = iPointZero;
		PlayerBehave be;
		if (keyStat & keyboard_left) v.x = -1;
		else if (keyStat & keyboard_right) v.x = 1;
		//if (keyStat & keyboard_up) v.y = -1;
		else if (keyStat & keyboard_down) v.y = 1;

	}

	if (getKeyDown() & keyboard_down) // 아래점프 아래바닥보다 한칸밑이 갈수 있는곳이면 아랫점프를 시도함!
	{

		int sx = hero->getPosition().x;
		sx /= MapTileWidth;

		int sy = hero->getPosition().y;
		sy /= MapTileHeight;
		sy += 2;// 아랫칸인덱스

		if (tiles[sy * MapTileNumX + sx] == canMove)
		{
			iPoint jumpVector = iPointMake(hero->getPosition().x, hero->getPosition().y + 1);
			hero->setPosition(jumpVector);
		}
	}

	if (hero->behave != PlayerBehave_meleeAttack)
	{
		keyStat = getKeyStat();
		keyDown = getKeyDown();
	}
	iPoint v = iPointZero;
	PlayerBehave be;
	if (keyStat & keyboard_left) v.x = -1;
	else if (keyStat & keyboard_right) v.x = 1;
	//if (keyStat & keyboard_up) v.y = -1;
	else if (keyStat & keyboard_down) v.y = 1;




	if (hero->alive)
	{

		if (mouseMove) // 마우스 입력이 있을때
		{
			if (hero->moveForMouse(dt))
				mouseMove = false;

			if (v != iPointZero)
			{
				mouseMove = false;
				hero->setTargetPosition(hero->getPosition());
				hero->pathNum = hero->pathIndex;
			}
		}
		else // 키보드 입력일때
		{

			if (keyDown & keyboard_num1)
			{
				be = PlayerBehave_meleeAttack;

				hero->Skill1();

				zoomCamera(hero->getPosition() + offMt, 1.5);
				shakeCamera(30);

				//printf("%f %f \n", imgSkill->touchRect().origin.x, imgSkill->touchRect().origin.y); // 스킬 출력 위치
				for (int i = 0; i < orc_Num; i++)
				{
					//printf("orc %d : x: %f, y : %f\n",i, enermy[i]->getPosition().x, enermy[i]->getPosition().y); // 몬스터 충돌 위치
					if (containPoint(orcs[i]->getPosition(), hero->imgSkill->touchRect()))
					{
						((Orc*)orcs[i])->setDmg(5.f);
					}
				}
			}


			else if (keyDown & keyboard_space)
				be = PlayerBehave_jumpAndFall;
			else if (keyDown & keyboard_down)
				be = PlayerBehave_idle;
			else if (keyDown & keyboard_up)
				be = PlayerBehave_jumpAndFall;
			else
				be = (v == iPointZero ? PlayerBehave_idle : PlayerBehave_move);
			int dir = hero->direction;


			if (v.x < 0) dir = 0;
			else if (v.x > 0) dir = 1;

			if (hero->behave != PlayerBehave_meleeAttack && hero->behave != PlayerBehave_jumpAndFall)
				hero->setBehave(be, dir);
			float minX, maxX, minY, maxY;

			if (v != iPointZero)
			{
				v /= iPointLength(v);
				iPoint mp = v * (hero->getMovement() * dt);
				hero->move(mp + movement, maptile);

				minX = devSize.width * 0.333333f;
				maxX = devSize.width * 0.666667f;
				minY = devSize.height * 0.333333f;
				maxY = devSize.height * 0.666667f;
			}
			else// if(v == iPointZero)
			{
				hero->move(movement * 3, maptile);

				minX = devSize.width / 2;
				maxX = devSize.width / 2;
				minY = devSize.height / 2;
				maxY = devSize.height / 2;
			}


			iPoint vp = offMt + hero->getPosition();
			if (vp.x < minX)
			{
				// 왼쪽으로 넘어갔을 경우

				offMt.x += (minX - vp.x) * dt;
				if (offMt.x > 0)
					offMt.x = 0;
			}
			else if (vp.x > maxX)
			{

				// 오른쪽으로 넘어갔을 경우
				offMt.x += (maxX - vp.x) * dt;
				if (offMt.x < devSize.width - MapTileWidth * MapTileNumX)
					offMt.x = devSize.width - MapTileWidth * MapTileNumX;
			}
			if (vp.y < minY)
			{
				// 위로 넘어갔을 경우
				offMt.y += (minY - vp.y) * dt;
				if (offMt.y > 0)
					offMt.y = 0;
			}
			else if (vp.y > maxY)
			{
				// 아래로 넘어갔을 경우
				offMt.y += (maxY - vp.y) * dt;
				if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
					offMt.y = devSize.height - MapTileHeight * MapTileNumY;
			}
		}
	}

	setRGBA(1, 1, 1, 1);
	hero->paint(dt, offMt);
	setRGBA(1, 1, 1, 1);

	//printf("%f %f || ", offMt.x, offMt.y);
	//printf("%f %f\n", hero->getPosition().x - offMt.x, hero->getPosition().y - offMt.y);
}

void drawOrc(float dt)
{ // paint Orc
	for (int i = 0; i < orcNum; i++)
	{
		if (orcs[i]->alive == false)
		{
			orcNum--;
			delete orcs[i];
			orcs[i] = orcs[orcNum];
			continue;
		}
		orcs[i]->paint(dt, offMt);
	}
	
	killIndicator->setString("%d", hero->kill);
}

#if _DEBUG
void debugHitbox(float dt)
{
	//hitbox orc
	for (int i = 0; i < orc_Num; i++)
		drawRect((orcs[i]->getPosition().x - orcs[i]->getSize().width / 2) + offMt.x, (orcs[i]->getPosition().y - orcs[i]->getSize().height) + offMt.y, orcs[i]->getSize().width, orcs[i]->getSize().height);

	//hitbox player
	drawRect((hero->getPosition().x - hero->getSize().width / 2) + offMt.x,
		(hero->getPosition().y - hero->getSize().height) + offMt.y, hero->getSize().width, hero->getSize().height);
}
#endif

