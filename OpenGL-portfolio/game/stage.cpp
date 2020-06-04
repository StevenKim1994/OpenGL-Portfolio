#pragma once
#include "stage.h"



#define ON_HITBOX 0

// 게임 씬 관련
extern int gameState;

// 좌표 및 카메라관련
iPoint offMt; // 카메라 오프셋
iPoint vp;
iShortestPath* sp;
bool mouseMove = false;


//object
Object** goblins;
Player* hero;


// 오브젝트 풀 관련
int _goblinNum = goblin_Num;
int goblinNum = _goblinNum;


//맵 관련
static MapTile* maptile;
static Texture** tileset;
static Texture* texFboStage;
static Texture* stageLogo;

float gameTime = 0;
float _gameTime = 100000000000;
static float logoDt = 0.0;

Player* minimapHero;





int tiles[stageMapTileNumX * stageMapTileNumY] =
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

void loadStage()
{
	///////////////// freeStageToEndStage
	texFboStage = createTexture(devSize.width, devSize.height);
	
	setStringSize(30);
	setRGBA(1, 1, 1, 1);

	tileset = (Texture**)malloc(sizeof(Texture*) * 1520);
	for (int i = 0; i < 1520; i++)
	{
		Texture* tex = createImage("assets/stage/tileset/mapsplit/tile%03d.png", i);
		tex->width *= 2;
		tex->height *= 2;
		tex->potWidth *= 2;
		tex->potHeight *= 2;
		tileset[i] = tex;
	}
	
	setRGBA(1, 1, 1, 1);

	int i, num = stageMapTileNumX * stageMapTileNumY;
	maptile = (MapTile*)malloc(sizeof(MapTile) * num);
	for (i = 0; i < num; i++)
	{
		MapTile* t = &maptile[i];
		t->attr = tiles[i];
	}

	goblinNum = _goblinNum;
	goblins = (Object**)malloc(sizeof(Object) * goblin_Num);
	for (int i = 0; i < goblin_Num; i++) // 맵에 오크 생성
	{
		Goblin* goblin = new Goblin(i);
		goblin->setPosition(iPointMake(MapTileWidth * 30 + (i * MapTileWidth+30), MapTileHeight*17));
		goblin->alive = true;
		goblins[i] = goblin;
	}

	sp = new iShortestPath();
	sp->init(tiles, stageMapTileNumX, stageMapTileNumY);

	///////////////// freeStageKeep
	iGraphics* g = iGraphics::instance();
	{
		setRGBA(0, 0, 0, 0);
		iSize logoSize = iSizeMake(500, 70);
		setRGBA(1, 1, 1, 0);
		g->init(logoSize);
		g->fillRect(0, 0, logoSize.width, logoSize.height);

		setStringSize(70);
		setStringRGBA(0, 0, 0, 1);
		g->drawString(logoSize.width/2, logoSize.height/2,HCENTER|VCENTER,"Waterfront");
		stageLogo = g->getTexture();
	}

	hero = new Player(); // 플레이어 캐릭터 생성
	minimapHero = new Player(); // 미니맵 플레이어
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

		hero->setDamage(5.0f);
	}

	// camera positioning Initialize
	{
		offMt = hero->getPosition();
		offMt = iPointMake(0, -5000);
	}	

	createPopPlayerUI();
	createPopMenuUI();
	createPopQuitAnswerUI();
	createPopGameOverUI();
	createPopPlayerInventory();

	loadProjectile();
	loadNumber();
	loadEffectHit();
	loadCoin();

	logoDt = 0.0f;
}

void freeStage()
{
	freeStageToEndStage();
	freeStageKeep();
}

void freeStageToEndStage()
{
	freeImage(texFboStage);

	for (int i = 0; i < 1520; i++)
		freeImage(tileset[i]);
	free(tileset);

	free(maptile);

	for (int i = 0; i < goblinNum; i++)
		delete goblins[i];
	free(goblins);

	delete sp;

//hero는 다음Stage에서 사용되므로 delete 하지 않음!
//UI는 여기서 생성되고 게임오버할떄 까지 계속쓰이므로 게임오버할떄 지운다
	// freeImage(stageLogo);

	// delete hero;
	// delete minimapHero;

	//freePopPlayerUI();
	//freePopMenuUI();
	//freePopQuitAnswerUI();
	//freePopGameOverUI();
	//freePopPlayerInventory();
	//
	//freeProjectile();
	//freeNumber();
	//freeEffectHit();
	freeCoin();
}

void freeStageKeep()
{
	//freeImage(texFboStage);
	//
	//for (int i = 0; i < 1520; i++)
	//	freeImage(tileset[i]);
	//free(tileset);
	//
	//free(maptile);
	//
	//for (int i = 0; i < goblin_Num; i++)
	//	delete goblins[i];
	//free(goblins);
	//
	//delete sp;

	//hero는 다음Stage에서 사용되므로 delete 하지 않음!
	//UI는 여기서 생성되고 게임오버할떄 까지 계속쓰이므로 게임오버할떄 지운다
	freeImage(stageLogo);

	delete hero;
	delete minimapHero;

	freePopPlayerUI();
	freePopMenuUI();
	freePopQuitAnswerUI();
	freePopGameOverUI();
	freePopPlayerInventory();
	
	freeProjectile();
	freeNumber();
	freeEffectHit();
	//freeCoin();
}


void drawStage(float dt)
{
	fbo->bind(texFboStage);
	drawMapTile(dt, tiles,maptile,tileset, stageMapTileNumX, stageMapTileNumY);
	drawGoblin(dt, tiles,maptile, stageMapTileNumX, stageMapTileNumY);
	drawHero(dt, tiles, maptile, stageMapTileNumX, stageMapTileNumY);
	drawCoin(dt, offMt, maptile);
	drawProjectile(dt, offMt);
	drawEffectHit(dt, offMt);
	drawNumber(dt, offMt);

#if _DEBUG
	debugHitbox(dt, tiles, maptile, stageMapTileNumX, stageMapTileNumY);
#endif
	
	fbo->unbind();
	showCamera(texFboStage, dt);
	
	setRGBA(1, 1, 1, 1);
	fbo->bind(minimapFbo);
	drawMinimapTile(dt, tiles, maptile, tileset, stageMapTileNumX, stageMapTileNumY);
	drawMinimapHero(dt, tiles, maptile, stageMapTileNumX, stageMapTileNumY);
	fbo->unbind();


	drawPopPlayerUI(dt);
	drawPopMenuUI(dt);
	drawPopGameOverUI(dt);
	drawPopPlayerInventory(dt);
	
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
		setLoading(gs_endStage, freeStageToEndStage, loadEndStage); // 다음 씬으로! loadendStage()
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


	if (hero->exp >= 100)
	{
		hero->setLevel(hero->getLevel() + 1);
		hero->exp = hero->exp - 100.0f;
		hero->setHP(hero->getMaxHp());
		hero->setMP(hero->getMaxMP());
		hero->setStamina(hero->getStamina());
		audioPlay(6);
	}

}

void keyStage(iKeyState stat, iPoint point)
{
	if (keyPopMenuUI(stat, point))
		return;
	
	if (keyPopGameOverUI(stat, point))
		return;

	if(keyPopQuitAnswerUI(stat, point))
		return;

	
	
	keyPopPlayerUI(stat, point);

	keyPopPlayerInventory(stat, point);
	
		

		
	if (stat == iKeyState::iKeyStateBegan)
	{

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

		sp->dijkstra(sy * stageMapTileNumX + sx, ey * stageMapTileNumX + ex, hero->path, hero->pathNum);
		
		sp->removeDuplicate(hero->path, hero->pathNum);
		hero->setTargetPosition(hero->getPosition());
		hero->pathIndex = 1;

		mouseMove = true;
	}


}

