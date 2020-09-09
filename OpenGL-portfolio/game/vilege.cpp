#pragma once

#include "vilege.h"

// 게임 씬 관련
extern int gameState;

int Vilegetiles[40 * 22] =
{ 01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,
99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,

};

extern iShortestPath* sp;

static Texture* vilegeTileset[880];
 MapTile* vilegemaptile;
static Texture* texFboVilege;
static Texture* stageLogo;
extern Texture* minimapFbo;

extern iPoint offMt;
extern Player* hero;

Object** ghostwarriors;



extern iStrTex* killIndicator;
extern iStrTex* timeIndicator;
extern iStrTex* hpIndicator;
extern iStrTex* mpIndicator;
extern iStrTex* staminaIndicator;
extern iStrTex* moneyIndicator;
extern iStrTex* expIndicator;
extern iStrTex* nameIndicator;

extern float gameTime;
extern float _gameTime;
extern bool mouseMove;

static float logoDt;

void loadVillege()
{
	gameState = gs_villege; 

	
	hero->setPosition(iPointZero);

	logoDt = 0.0f;
	texFboVilege = createTexture(devSize.width, devSize.height);

	iGraphics* g = iGraphics::instance();
	setRGBA(0, 0, 0, 0);
	iSize logoSize = iSizeMake(500, 70);
	setRGBA(1, 1, 1, 0);
	g->init(logoSize);
	g->fillRect(0, 0, logoSize.width, logoSize.height);

	setStringSize(70);
	setStringRGBA(0, 0, 0, 1);
	g->drawString(logoSize.width / 2, logoSize.height / 2, HCENTER | VCENTER, "Vilege");
	stageLogo = g->getTexture();

	setStringSize(30);

	setRGBA(1, 1, 1, 1);
	for (int i = 0; i < 880; i++)
	{
		Texture* tex = createImage("assets/stage/tileset/vilege/tile%03d.png", i);
		tex->width *= 1;
		tex->height *= 1;
		tex->potWidth *= 1;
		tex->potHeight *= 1;
		vilegeTileset[i] = tex;
	}
	
	setRGBA(1, 1, 1, 1);

	int num = vilegeTileNumX * vilegeTileNumY;
	vilegemaptile = (MapTile*)malloc(sizeof(MapTile) * num);
	for (int i = 0; i < num; i++)
	{
		MapTile* t = &vilegemaptile[i];
		t->attr = Vilegetiles[i];
	}

	offMt = hero->getPosition();

	sp = new iShortestPath();
	sp->init(Vilegetiles, vilegeTileNumX, vilegeTileNumY);

	ghostwarriors = (Object**)malloc(sizeof(Object) * 1);
	for (int i = 0; i < 1; i++)
	{
		GhostWarrior* gw = new GhostWarrior(i);
		gw->setPosition(iPointMake(MapTileWidth*35, MapTileHeight * 13));
		gw->oldPosition = iPointMake(MapTileWidth * 35, MapTileHeight * 130);
		gw->targetPosition = gw->getPosition();
		gw->alive = true;
		ghostwarriors[i] = gw;

		gw->setBehave(ObjectBehave::ObjectBehave_idle, gw->direction);
	}


	createPopPlayerUI();
	createPopMenuUI();
	createPopQuitAnswerUI();
	createPopGameOverUI();
	loadNumber();
	loadEffectHit();
	loadProjectile();
}

void freeVillege()
{

	for (int i = 0; i < 1; i++)
		delete ghostwarriors[i];

	free(ghostwarriors);

	freeNumber();
	freeEffectHit();
	freeProjectile();

	freePopPlayerUI();
	freePopMenuUI();
	freePopQuitAnswerUI();
	freePopGameOverUI();
	freePopStageNPCMenuUI();

}

void drawVillege(float dt)
{
	fbo->bind(texFboVilege);

	drawMapTile(dt, Vilegetiles, vilegemaptile, vilegeTileset, vilegeTileNumX, vilegeTileNumY);
	for (int i = 0; i < 1; i++)
	{
		// 여기 죽었을때 부분 추가해야함
		((GhostWarrior*)ghostwarriors[i])->paint(dt, offMt, vilegemaptile, vilegeTileNumX, vilegeTileNumY);
	
	}

	drawHero(dt, Vilegetiles, vilegemaptile, vilegeTileNumX, vilegeTileNumY);



	fbo->unbind();
	
	fbo->bind(minimapFbo);
	fbo->clear(1, 1, 1, 0);
	fbo->unbind();
	showCamera(texFboVilege, dt);

	drawNumber(dt, offMt);
	drawEffectHit(dt, offMt);
	drawProjectile(dt, offMt);

	drawPopPlayerUI(dt);
	drawPopMenuUI(dt);
	drawPopQuitAnswerUI(dt);
	drawPopGameOverUI(dt);

	if (hero->alive == false) // 플레이어가 죽으면 
	{
		printf("Player is Dead\n");
		showPopGameOverUI(true);
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

	moneyIndicator->setString("%d", hero->money);

	if (hero->exp >= 100)
	{
		hero->setLevel(hero->getLevel() + 1);
		hero->exp = 0.0f;
		hero->setHP(hero->getMaxHp());
		hero->setMP(hero->getMaxMP());
		hero->setStamina(hero->getStamina());
		nameIndicator->setString("%d", hero->getLevel());
	}



}

void keyVilliege(iKeyState stat, iPoint point)
{

	if (keyPopGameOverUI(stat, point))
		return;

	if (keyPopQuitAnswerUI(stat, point))
		return;


	if (keyPopMenuUI(stat, point))
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

	
		hero->setTargetPosition(hero->getPosition());
		hero->pathIndex = 1;

		mouseMove = true;
	}

}
