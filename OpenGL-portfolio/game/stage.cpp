#pragma once
#include "stage.h"
#include "stageTileInfo.h"
#include "Monster.h"
#include "Player.h"
#include "Orc.h"
#include "sceneManager.h"
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

#define orc_Num 3

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
		Orc* orc = new Orc();
		orc->setPosition(iPointMake(MapTileWidth * 30 + (i * MapTileWidth), MapTileHeight*17));
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

//----------------PopPlayerUI------------------------//

iPopup* PopPlayerUI;
iImage** PopPlayerUIImgs;
Texture* Poptex;
iPopup* PopMenuUI;

//const char* slotString[5] = { "Name", "HP", "MP", "Stamina", "Menu" };

const char* mapTitle[1] = { "Waterfront" };
void createPopPlayerUI()
{
	iPopup* pop = new iPopup(iPopupStyleNone);
	iGraphics* g = iGraphics::instance();
	iImage* img = new iImage();
	iSize size = iSizeMake(devSize.width, devSize.height); // 크기를 화면크기랑 동일하게 사용자의 화면을 그래도 덮는 UI Layer

	PopPlayerUIImgs = (iImage**)malloc(sizeof(iImage*) * 5);


	// Stage Title
	{

		g->init(size);
		setStringRGBA(0, 0, 0, 1);
		setRGBA(1, 1, 1, 0);// alpha값은 0 투명한 사이즈의 화면크기의 상자를 만드는거니까
		g->fillRect(0, 0, devSize.width, devSize.height);
		g->drawString(devSize.width / 2, 10, HCENTER | VCENTER, "- Stage -");
		g->drawString(devSize.width / 2, 35, HCENTER|VCENTER, mapTitle[0]);
		g->drawString(devSize.width / 2, 65, HCENTER | VCENTER, "KILL:");
	
		Poptex = g->getTexture();
		img->addObject(Poptex);
		freeImage(Poptex);
		pop->addObject(img);

	}

	// kill indicator
	{
		setRGBA(1, 1, 1, 1);
		iImage* kill_indicator = new iImage();
		kill_indicator->addObject(killIndicator->tex);
		kill_indicator->position = iPointMake(devSize.width / 2, 90);
		pop->addObject(kill_indicator);
	}
	
	// time indicator
	{
		setRGBA(1, 1, 1, 1);
		iImage* time_indicator = new iImage();
		time_indicator->addObject(timeIndicator->tex);
		time_indicator->position = iPointMake(devSize.width / 2 - 200, 130);
		pop->addObject(time_indicator);
	}


	{ // 미니맵
		setRGBA(1, 1, 0, 1);
		setStringSize(10);
		iSize mapsize = iSizeMake(200, 200);
		g->init(mapsize);
		g->fillRect(0, 0, mapsize.width, mapsize.height);
		g->drawString(mapsize.width / 2, mapsize.height / 2, HCENTER | VCENTER, "Minimap position");
		Texture* minimapTex = g->getTexture();
		iImage* minimap = new iImage();
		minimap->addObject(minimapTex);
		minimap->position = iPointMake(devSize.width - mapsize.width, 60);
		pop->addObject(minimap);

	}

	
	// Stage Menu
	{
		setStringSize(30);
		iImage* menuBtn = new iImage();
		Texture* menuBtnTex;
		iSize menuSize = iSizeMake(200, 100);
		g->init(menuSize);
		setRGBA(0, 0, 1, 1);
		g->fillRect(0, 0, menuSize.width, menuSize.height);
		g->drawString(menuSize.width / 2, menuSize.height / 2, HCENTER | VCENTER, "Menu");
		
		menuBtnTex = g->getTexture();
		menuBtn->addObject(menuBtnTex);
		freeImage(menuBtnTex);

		menuBtn->position =iPointMake(devSize.width - menuSize.width, 10);
		PopPlayerUIImgs[0] = menuBtn;
		pop->addObject(menuBtn);

	}

	// PlayerInfo // 나중에 반복문으로 리팩터링 해야할 부분 #refactoring
	{
		iImage* playerImage = new iImage();
		iImage* playerName = new iImage();
		iImage* playerHP = new iImage();
		iImage* playerMP = new iImage();
		iImage* playerStamina = new iImage();
	
		Texture* infoTex;
		iSize infoSize = iSizeMake(200, 100);
		setRGBA(0, 1, 0, 1);

		// Player Portrait
		
		setRGBA(1, 1, 1, 1);
		playerImage->addObject(playerPortrait);
		playerImage->position = iPointMake(0, 10);
		PopPlayerUIImgs[1] = playerImage;
		pop->addObject(playerImage);

		// Player Name Indicator

		setStringSize(30);
		g->init(infoSize);
		g->drawString(infoSize.width / 2, infoSize.height / 2, HCENTER | VCENTER, "%s", hero->getName());
		infoTex = g->getTexture();
		playerName->addObject(infoTex);
		freeImage(infoTex);
		playerName->position = iPointMake(70, 15);
		pop->addObject(playerName);
		

	
		infoSize = iSizeMake(200, 50);
		setRGBA(1, 0, 0, 1);
		setStringSize(15);
		// HP Indicator
		g->init(infoSize);
		g->fillRect(0, 0, infoSize.width * (hero->getHp() / hero->getMaxHp()), infoSize.height);
		g->drawString(infoSize.width / 2, infoSize.height / 2, HCENTER | VCENTER, "HP: %.1f / %.1f", hero->getHp() , hero->getMaxHp());

		infoTex = g->getTexture();
		playerHP->addObject(infoTex);
		freeImage(infoTex);

		playerHP->position = iPointMake(0, 110);

		PopPlayerUIImgs[2] = playerHP;
		pop->addObject(playerHP);
		

		// MP Indicator
		setRGBA(0, 0, 1, 1);
		g->init(infoSize);
		g->fillRect(0, 0, infoSize.width * (hero->getMp() / hero->getMaxMP()), infoSize.height);
		g->drawString(infoSize.width / 2, infoSize.height / 2, HCENTER | VCENTER, "MP: %.1f / %.1f", hero->getMp() , hero->getMaxMP());

		infoTex = g->getTexture();
		playerMP->addObject(infoTex);
		freeImage(infoTex);

		playerMP->position = iPointMake(0, 160);

		PopPlayerUIImgs[3] = playerMP;
		pop->addObject(playerMP);

		setRGBA(1, 1, 0, 1);

		// Stamina Indicator
		g->init(infoSize);
		g->fillRect(0, 0, infoSize.width * (hero->getStamina() / hero->getMaxStamina()), infoSize.height);
		g->drawString(infoSize.width / 2, infoSize.height / 2, HCENTER | VCENTER, "Stamina: %.1f / %.1f", hero->getStamina(), hero->getMaxStamina());

		infoTex = g->getTexture();
		playerStamina->addObject(infoTex);
		freeImage(infoTex);

		playerStamina->position = iPointMake(0, 210);

		PopPlayerUIImgs[4] = playerStamina;
		pop->addObject(playerStamina);


		

	}


	pop->openPosition = iPointZero;
	pop->closePosition = iPointZero;

	PopPlayerUI = pop;
	setRGBA(1, 1, 1, 1);

}

void freePopPlayerUI()
{
	delete PopPlayerUI;
}

void drawPopPlayerUI(float dt)
{
	PopPlayerUI->paint(dt);
}

bool keyPopPlayerUI(iKeyState stat, iPoint point)
{

	int i, j = -1;

	switch (stat)
	{
		case iKeyStateBegan:
			i = PopPlayerUI->selected;

			if (i == -1)
				break;

			else if(i == 0)
			{
				printf("selected = %d\n", i);

				if (PopMenuUI->bShow == false)
					showPopMenuUI(true);

				else
					showPopMenuUI(false);
			}

		
			else
				printf("seletecd = %d\n", i);
			break;
	
		case iKeyStateMoved:

			for (i = 0; i < 5; i++)
			{
				if (containPoint(point, PopPlayerUIImgs[i]->touchRect(PopPlayerUI->closePosition)))
				{
					j = i;
					break;
				}
			}
			PopPlayerUI->selected = j;
			break;
	
		case iKeyStateEnded:

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
		img->position = iPointMake(0,0);

		pop->addObject(img);
	}

	// buttons
	{
		setRGBA(0, 1, 1, 1);
		setStringRGBA(0, 0, 0, 1);
		setStringSize(20);
		
		iSize btnSize = iSizeMake(300, 30);
		
		for(int i= 0; i<3; i++)
		{
			Texture* tex;
			iImage* btnImg = new iImage();
			
			g->init(btnSize);
			g->fillRect(0,0,btnSize.width, btnSize.height);
			g->drawString(btnSize.width / 2, btnSize.height / 2, HCENTER | VCENTER, btnString[i]);

			tex = g->getTexture();
			btnImg->addObject(tex);
			freeImage(tex);

			btnImg->position = iPointMake((size.width - btnSize.width) /2,i*100 +15);
			
			PopMenuUIImgs[i] = btnImg;
			pop->addObject(btnImg);
		
		}
		
	}


	// 메뉴창에 간단하게 게임 설명(목표) 넣는 부분




	
	pop->openPosition = iPointMake((devSize.width - size.width) / 2,(devSize.height - size.height)/2);
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
	case iKeyStateBegan:
	{
		i = PopMenuUI->selected;

		if (i == -1)
			break;

		else if (i == 0)
		{
			printf("selected = %d\n", i);
			PopMenuUI->show(false);

		}


		else if (i == 1)
		{

		}

		else if (i == 2)
		{
			printf("QuitANSWER?\n");
			showPopQuitAnswerUI(true);
		}

		printf("seletecd = %d\n", i);
		break;
	}

	case iKeyStateMoved:
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
		printf("seletecd = %d\n", PopMenuUI->selected);
		break;
	}
	case iKeyStateEnded:
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

iPopup* PopQuitAnswerUI;
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
		g->drawString(size.width / 2, size.height /2 -175, VCENTER | HCENTER, "Do you want exit?");
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
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnUISlot[i]);
				btnTex = g->getTexture();
			}

			answerBtn->addObject(btnTex);
			answerBtn->position = iPointMake(devSize.width/2 * (i+1)+ 150, size.height + 10);
			freeImage(btnTex);
		}
		
		pop->addObject(answerBtn);

		PopQuitAnswerUIBtn[i] = answerBtn;

	}

	pop->openPosition = iPointMake(devSize.width /2 - size.width -100 , devSize.height/2 -size.height);
	pop->closePosition = pop->openPosition;
	PopQuitAnswerUI = pop;

}

void freePopQuitAnswerUI()
{
	delete PopQuitAnswerUI;
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
		case iKeyStateBegan:
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

		case iKeyStateMoved :
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

		case iKeyStateEnded:
			break;
	}

	return true;
}

void showPopQuitAnswerUI(bool show)
{
	PopQuitAnswerUI->show(show);
}

struct Damage
{
	iStrTex* stDamage;
	iPoint p;
	float delta;

	bool paint(float dt, iPoint off);
};
#define Damage_delta 1.0f

Damage* _damage;
Damage** damage;
int damageNum;
#define _damageNum 100

Texture* methodStDamage(const char* str);

void loadNumber()
{
	_damage = (Damage*)malloc(sizeof(Damage) * _damageNum);
	for (int i = 0; i < _damageNum; i++)
	{
		Damage* d = &_damage[i];
		d->stDamage = new iStrTex(methodStDamage);
		d->p = iPointZero;
		d->delta = Damage_delta;
	}

	damage = (Damage**)malloc(sizeof(Damage*) * _damageNum);
	damageNum = 0;
}

void freeNumber()
{
	for (int i = 0; i < _damageNum; i++)
		delete _damage[i].stDamage;
	free(_damage);
	free(damage);
}
void drawNumber(float dt, iPoint off)
{
	for (int i = 0; i < damageNum; i++)
	{
		if (damage[i]->paint(dt, off))
		{
			damageNum--;
			for (int j = i; j < damageNum; j++)
				damage[j] = damage[1 + j];
			i--;
		}
	}
}
void addNumber(int dmg, iPoint position)
{
	for (int i = 0; i < _damageNum; i++)
	{
		Damage* d = &_damage[i];
		if (d->delta >= Damage_delta)
		{
			d->stDamage->setString("%d", dmg);
			d->p = position;
			d->delta = 0.0f;

			damage[damageNum] = d;
			damageNum++;
			return;
		}
	}
}

//------------PopGameOverUI---------------//

iPopup* PopGameOver;
iImage** GameOverBtn;
const char* btnStr[2] = { "MainMenu", "Game Quit" };

void createPopGameOverUI()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(devSize.width , devSize.height);
	setRGBA(1, 0, 0, 1);
	fillRect(0, 0, devSize.width, devSize.height);


	GameOverBtn = (iImage**)malloc(sizeof(iImage*) * 2); // 0 : 메인메뉴 1 : 게임종료


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

	pop->openPosition = iPointMake(devSize.width / 2 - size.width , devSize.height /2 - size.height);
	pop->closePosition = pop->openPosition;
	
	PopGameOver = pop;
}

void freePopGameOverUI()
{
	delete PopGameOver;
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
	case iKeyStateBegan:
	{
		i = PopGameOver->selected;

		if (i == -1)
			break;

		if (i == 0)
		{
			setLoading(gs_menu, freeStage, loadMenu);
		}

		else if (i == 1)
		{
			extern bool runWnd;
			runWnd = false;
		}
		break;
	}

	case iKeyStateMoved:
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

	case iKeyStateEnded:
		break;
	
	}

	return true;
}

void showPopGameOverUI(bool show)
{
	PopGameOver->show(show);
}

Texture* methodStDamage(const char* str)
{
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(100, 20);

	setRGBA(1, 1, 1, 0);
	g->init(size);
	g->fillRect(0, 0, size.width, size.height);
	
	setRGBA(1,1, 1, 1);
	setStringSize(20);
	setStringRGBA(1, 0, 0, 1);
	g->drawString(size.width / 2 , size.height / 2, HCENTER|VCENTER, str);


	return g->getTexture();

}

bool Damage::paint(float dt, iPoint off)
{
	float r = delta / Damage_delta;
	iPoint pp = p + off + iPointMake(0, -easeIn(r, 0, 200));
	float a = 1.0f - r;
	setRGBA(1, 1, 1, a);
	stDamage->paint(pp.x, pp.y, VCENTER | HCENTER);
	setRGBA(1, 1, 1, 1);

	delta += dt;
	if (delta < Damage_delta)
		return false;
	return true;
}
