#pragma once

#include "iStd.h"

#include "GameUI.h"

#include "drawObject.h"
#include "Player.h"

#include "vilege.h"
#include "../GameObject/NPC/stageNPC.h"
#include "../GameObject/Prop/Fire.h"
#include "../GameObject/Enermy/Mushroom.h"
#include "GameEffect.h"

void loadEndStage();
void freeEndStage();
void drawEndStage(float dt);
void keyEndStage(iKeyState stat, iPoint point);

