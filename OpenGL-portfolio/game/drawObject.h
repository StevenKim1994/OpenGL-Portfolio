#pragma once

#include "iStd.h"

#include "GameUI.h"

#define _logoDt 1.0f
// drawMapTile
void drawMapTile(float dt, int* tiledata, MapTile* tile, Texture** tileset, int NumX, int NumY);

// ctrl - hero
void drawHero(float dt, int* tiledata, MapTile* tile, int NumX, int NumY);
// ctrl - orc
void drawGoblin(float dt, int* tiledata, MapTile* tile, int NumX, int NumY);

// debugHitbox
#if _DEBUG
void debugHitbox(float dt, int* tiledata, MapTile* tile, int NumX, int NumY);
#endif

void drawMinimapTile(float dt, int* tiledata, MapTile* tile, Texture** tileset, int NumX, int NumY);
void drawMinimapHero(float dt, int* tiledata, MapTile* tile, int NumX, int NumY);