#pragma once

#include "iStd.h"

#include "GameUI.h"

#define _logoDt 1.0f
// drawMapTile
void drawMapTile(float dt);

// ctrl - hero
void drawHero(float dt);
// ctrl - orc
void drawOrc(float dt);

// debugHitbox
#if _DEBUG
void debugHitbox(float dt);
#endif


void drawEndStageMapTile(float dt);
