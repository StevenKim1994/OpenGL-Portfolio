#include "endstage.h"

#include "Player.h"

#include "vilege.h"
#include "../GameObject/NPC/stageNPC.h"

// 게임 씬 관련
extern int gameState;


extern Player* hero;
extern iPoint offMt;
extern iPoint vp;
extern iShortestPath* sp;

extern iStrTex* killIndicator;
extern iStrTex* timeIndicator;
extern iStrTex* hpIndicator;
extern iStrTex* mpIndicator;
extern iStrTex* staminaIndicator;

static float logoDt;
static Texture* stageLogo;
static Texture* texFboStage;


static Texture* endStageTileset[1521];

static MapTile* endStagemaptile;
stageNPC* stagenpc;

extern float gameTime;
extern float _gameTime;
extern bool mouseMove;



int endStagetiles[endStageMapTileNumX * endStageMapTileNumY] =
{
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 33, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 77,
99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 44, 44, 44, 44, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 44, 44, 44, 44, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
};
 // 01 : canMove
 // 99 : canNotMove
 // 44 : deadZone 
// 33 : NPC Position

void loadEndStage()
{
	logoDt = 0.0;
	texFboStage = createTexture(devSize.width, devSize.height);

	iGraphics* g = iGraphics::instance();
	setRGBA(0, 0, 0, 0);
	iSize logoSize = iSizeMake(500, 70);
	setRGBA(1, 1, 1, 0);
	g->init(logoSize);
	g->fillRect(0, 0, logoSize.width, logoSize.height);

	setStringSize(70);
	setStringRGBA(0, 0, 0, 1);
	g->drawString(logoSize.width / 2, logoSize.height / 2, HCENTER | VCENTER, "Cave");
	stageLogo = g->getTexture();

	setStringSize(30);

	setRGBA(1, 1, 1, 1);
	for (int i = 0; i < 1520; i++)
	{
		Texture* tex = createImage("assets/stage/tileset/endstage/tile%03d.png", i);
		tex->width *= 2;
		tex->height *= 2;
		tex->potWidth *= 2;
		tex->potHeight *= 2;
		endStageTileset[i] = tex;
	}

	setRGBA(1, 1, 1, 1);
	
	int i, num = endStageMapTileNumX * endStageMapTileNumY;
	endStagemaptile = (MapTile*)malloc(sizeof(MapTile) * num);
	for (int i = 0; i < num; i++)
	{
		MapTile* t = &endStagemaptile[i];
		t->attr = endStagetiles[i];
	}

	hero->setPosition(iPointMake(MapTileWidth * 0, MapTileHeight * 19));
	offMt = hero->getPosition();

	sp = new iShortestPath();
	sp->init(endStagetiles, endStageMapTileNumX, endStageMapTileNumY);

	stagenpc = new stageNPC();
	stagenpc->setPosition(iPointMake(MapTileWidth * 47, MapTileHeight * 13));
	stagenpc->setSize(iSizeMake(32, 32));


	createPopPlayerUI();
	createPopMenuUI();
	createPopQuitAnswerUI();
	createPopGameOverUI();
	createPopStageNPCMenuUI();
	loadNumber();
	
}
void freeEndStage()
{
	freeImage(texFboStage);

	for (int i = 0; i < 1520; i++)
		delete endStageTileset[i];
	free(endStagemaptile);

	delete sp;
	delete stagenpc;


	freeNumber();
	//freePopPlayerUI();
	//freePopMenuUI();
	//freePopQuitAnswerUI();
	//freePopGameOverUI();
	//freePopStageNPCMenuUI();
	// UI는 게임오버때 까지 계속쓰임
}
void drawEndStage(float dt)
{
	
	fbo->bind(texFboStage);
	drawMapTile(dt, endStagetiles,endStagemaptile,endStageTileset, endStageMapTileNumX, endStageMapTileNumY);
	drawHero(dt, endStagetiles, endStagemaptile, endStageMapTileNumX, endStageMapTileNumY);
	drawRect(hero->getPosition().x+offMt.x, hero->getPosition().y+offMt.y, hero->getSize().width, hero->getSize().height);
	stagenpc->paint(dt, offMt);
	fbo->unbind();

	showCamera(texFboStage, dt);

	drawPopPlayerUI(dt);
	drawPopMenuUI(dt);
	drawPopQuitAnswerUI(dt);

	drawPopGameOverUI(dt);
	drawPopStageNPCMenuUI(dt);
	drawNumber(dt, offMt);



	killIndicator->setString("%d", hero->kill);

	//timeIndicator->setString("TIME : %0.2f", gameTime);

	hpIndicator->setString("HP : %.1f / %.1f", hero->getHp(), hero->getMaxHp());

	mpIndicator->setString("MP : %.1f / %.1f", hero->getMp(), hero->getMaxMP());

	staminaIndicator->setString("Stamina : %.1f / %.1f", hero->getStamina(), hero->getMaxStamina());



	if (hero->getStamina() != hero->getMaxStamina())
	{
		hero->setStamina(hero->getStamina() + 0.1f);
		staminaIndicator->setString("%0.1f", (hero->getStamina()));

		if (hero->getStamina() > hero->getMaxStamina())
			hero->setStamina(hero->getMaxStamina());
	}

	

	if (hero->alive == false)
	{
		printf("Player is Dead!\n");
		showPopGameOverUI(true);
	}

	//MP charge
	if (hero->getMp() != hero->getMaxMP())
	{
		hero->setMP(hero->getMp() + 0.1f);
		mpIndicator->setString("%0.1f", (hero->getMp()));

		if (hero->getMp() > hero->getMaxMP())
			hero->setMP(hero->getMaxMP());
	}


	//stamina charge
	if (hero->getStamina() != hero->getMaxStamina())
	{
		hero->setStamina(hero->getStamina() + 0.1f);
		staminaIndicator->setString("%f", (hero->getStamina()));

		if (hero->getStamina() > hero->getMaxStamina())
			hero->setStamina(hero->getMaxStamina());
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
void keyEndStage(iKeyState stat, iPoint point)
{
	
	if (keyPopGameOverUI(stat, point))
		return;

	if (keyPopQuitAnswerUI(stat, point))
		return;

	if (keyPopMenuUI(stat, point))
		return;

	if (keyPopStageNPCMenuUI(stat, point))
		return;
	
	keyPopPlayerUI(stat, point);

	if (stat == iKeyState::iKeyStateBegan)
	{
		if (containPoint(point, iRectMake(stagenpc->getPosition().x+ offMt.x, stagenpc->getPosition().y+offMt.y, 32, 32))) // 엔피씨를 클릭한다면
		{
			printf("NPC Click!\n");
			showPopStageNPCMenuUI(true);
		
		}

		else // 갈수 있는 땅을 클릭한다면
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

			sp->dijkstra(sy * endStageMapTileNumX + sx, ey * endStageMapTileNumX + ex, hero->path, hero->pathNum);


	
			sp->removeDuplicate(hero->path, hero->pathNum);
			hero->setTargetPosition(hero->getPosition());
			hero->pathIndex = 1;

			mouseMove = true;
		}
	}
	else if(stat == iKeyState::iKeyStateMoved)
	{
		if (containPoint(point, iRectMake(stagenpc->getPosition().x + offMt.x, stagenpc->getPosition().y + offMt.y, 32, 32))) // 엔피씨를 마우스 오버한다면
		{
			printf("NPC mouseOver!\n");
		
		}
	}

	
}



