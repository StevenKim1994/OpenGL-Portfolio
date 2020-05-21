#pragma once

#include "iStd.h"

#include "GameUI.h"


void loadStage();
void freeStage();
void drawStage(float dt);
void keyStage(iKeyState stat, iPoint point);

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
