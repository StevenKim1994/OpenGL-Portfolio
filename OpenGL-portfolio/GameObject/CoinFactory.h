#pragma once
#include "iStd.h"
#include "../GameObject/Prop/coin.h"

void loadCoin();
void freeCoin();
void drawCoin(float dt, iPoint off, MapTile* maptile);
void checkCoin(iPoint p, iPoint off);
void addCoin(iPoint p, int price);
