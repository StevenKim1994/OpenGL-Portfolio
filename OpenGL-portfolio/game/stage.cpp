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
static Texture* tileset[1521];
static Texture* texFboStage;
static Texture* stageLogo;
Texture* minimapFbo;


// UI 관련
iStrTex* killIndicator;
iStrTex* timeIndicator;
iStrTex* hpIndicator;
iStrTex* mpIndicator;
iStrTex* staminaIndicator;
iStrTex* expIndicator;
iStrTex* moneyIndicator;
iStrTex* nameIndicator;

iStrTex* skillIndicator[3];

Texture* playerPortrait;
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
	goblinNum = _goblinNum;
	
	playerPortrait = createImage("assets/stage/hero/Knight/KnightPortrait.png");
	texFboStage = createTexture(devSize.width, devSize.height);
	minimapFbo = createTexture(devSize.width, devSize.height);

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

//		iGraphics* g = iGraphics::instance();
//		igImage* ig = g->createIgImage("assets/stage/tileset/mapsplit/tile%03d.png", i);
//		iSize igSize = iSizeMake(g->getIgImageWidth(ig) * 2.0, g->getIgImageHeight(ig) * 2.0);
//		g->init(igSize);
//		g->drawImage(ig, 0, 0, 2.0, 2.0, TOP | LEFT);
//		tileset[i] = g->getTexture(); // GDI+ 사용 확대 이러면 사이 간격이 생김

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

	killIndicator = new iStrTex(methodKillIndicator);
	killIndicator->setString("%d", hero->kill);

	hpIndicator = new iStrTex(methodPlayerHPIndicator);
	hpIndicator->setString("HP : %.1f / %.1f", hero->getHp(), hero->getMaxHp());

	mpIndicator = new iStrTex(methodPlayerMPIndicator);
	mpIndicator->setString("MP : %.1f / %.1f", hero->getMp(), hero->getMaxMP());

	staminaIndicator = new iStrTex(methodPlayerStaminaIndicator);
	staminaIndicator->setString("Stamina : %.1f / %.1f", hero->getStamina(), hero->getMaxStamina());

	expIndicator = new iStrTex(methodPlayerExpIndicator);
	expIndicator->setString("Exp : %.1f, / 100", hero->getExp());

	moneyIndicator = new iStrTex(methodPlayerMoneyIndicator);
	moneyIndicator->setString("%d", hero->money);

	nameIndicator = new iStrTex(methodPlayerNameIndicator);
	nameIndicator->setString("%d", hero->getLevel());

	skillIndicator[0] = new iStrTex(methodPlayerCooldownIndicator);
	skillIndicator[0]->setString("%1.0f", hero->_CoolDown_SK1 - hero->CoolDown_SK1);

	skillIndicator[1] = new iStrTex(methodPlayerCooldownIndicator);
	skillIndicator[1]->setString("%1.0f", hero->_CoolDown_SK2 - hero->CoolDown_SK2);

	skillIndicator[2] = new iStrTex(methodPlayerCooldownIndicator);
	skillIndicator[2]->setString("%1.0f", hero->_CoolDown_SK3 - hero->CoolDown_SK3);

	


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

	minimapFbo->width *= 0.5;
	minimapFbo->potWidth *= 0.5;
	minimapFbo->height *= 0.5;
	minimapFbo->potHeight *= 0.5;
	
}

void freeStage()
{
	freeImage(texFboStage);
	for (int i = 0; i < 1520; i++)
		delete tileset[i];
	
	free(maptile);

	for (int i = 0; i < goblinNum; i++)
		delete goblins[i];
	
	free(goblins);

	delete sp;

//hero는 다음Stage에서 사용되므로 delete 하지 않음!
//UI는 여기서 생성되고 게임오버할떄 까지 계속쓰이므로 게임오버할떄 지운다

	freeCoin();
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
	drawPopQuitAnswerUI(dt);
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

	moneyIndicator->setString("%d", hero->money);

	if (hero->exp >= 100)
	{
		
		hero->setLevel(hero->getLevel() + 1);
		hero->exp = hero->exp - 100.0f;
		hero->setHP(hero->getMaxHp());
		hero->setMP(hero->getMaxMP());
		hero->setStamina(hero->getStamina());
		nameIndicator->setString("%d", hero->getLevel());
		hpIndicator->setString("%0.1f", hero->getHp());
		mpIndicator->setString("%0.1f", hero->getMp());
		staminaIndicator->setString("%0.1f", hero->getStamina());
		audioPlay(6);
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

