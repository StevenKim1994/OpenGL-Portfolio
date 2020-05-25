#pragma once

#include "iStd.h"

#include "GameUI.h"

#define _logoDt 1.0f
// drawMapTile
void drawMapTile(float dt, MapTile* tile, Texture** tileset, int NumX, int NumY);

// ctrl - hero
void drawHero(float dt, MapTile* tile, int NumX, int NumY);
// ctrl - orc
void drawOrc(float dt, MapTile* tile, int NumX, int NumY);

// debugHitbox
#if _DEBUG
void debugHitbox(float dt, MapTile* tile, int NumX, int NumY);
#endif

