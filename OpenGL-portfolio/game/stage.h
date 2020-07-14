#pragma once

#include "iStd.h"


#include "drawObject.h"


#include "stageTileInfo.h"
#include "Monster.h"
#include "Player.h"
#include "Goblin.h"
#include "sceneManager.h"

#include "GameUI.h"
#include "GameEffect.h"
#include "CoinFactory.h"
#include "endstage.h"


void loadStage();
void freeStage();
void drawStage(float dt);
void keyStage(iKeyState stat, iPoint point);

