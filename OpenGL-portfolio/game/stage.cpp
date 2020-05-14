#pragma once
#include "stage.h"
#include "stageTileInfo.h"
#include "Player.h"
#include "Orc.h"


uint8 tileAttr[MapTileNumX * MapTileNumY] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,


};



#define ON_HITBOX 0

Player* hero;
MapTile* maptile;
iPoint offMt;
iPoint vp;

Orc** orcs;
Orc* orc;

#define orc_Num 3 // 맵에 존재하는 오크의 최대 마리수



void loadStage()
{



	int i, num = MapTileNumX * MapTileNumY;
	maptile = (MapTile*)malloc(sizeof(MapTile) * num);
	for (i = 0; i < num; i++)
	{
		MapTile* t = &maptile[i];
		t->attr = tileAttr[i];
		//t->imgIndex;
	}

	hero = new Player(); // 플레이어 캐릭터 생성

	hero->setSize(iSizeMake(PlayerWidth, PlayerHeight));

	hero->setMovement(MapCharMovement);
	hero->setPosition(iPointMake(MapTileWidth *30,MapTileHeight *45));
	offMt = hero->getPosition();// iPointZero;
	// camera positioning
	offMt = iPointMake(-320, -880+500);



	orcs = (Orc**)malloc(sizeof(Orc) * orc_Num);

	for (int i = 0; i < orc_Num; i++) // 맵에 오크 생성
	{
		orc = new Orc();
		orc->setPosition(iPointMake(MapTileWidth * 30 + (i * MapTileWidth), MapTileHeight*35));
		
		orcs[i] = orc;
	}



	createPopPlayerUI();
	createPopMenuUI();


	
}

void freeStage()
{
	freePopPlayerUI();
	freePopMenuUI();
	free(maptile);

	delete hero;
	
	for (int i = 0; i < orc_Num; i++)
	{
		delete orcs[i];
	}

	free(orcs);
	
}

void drawStage(float dt)
{
	iPoint movement = iPointMake(0, 1) * powGravity * dt;


	int i, num = MapTileNumX * MapTileNumY;
	for (i = 0; i < num; i++)
	{
		MapTile* t = &maptile[i];
		switch (t->attr) {
		case 0: setRGBA(tile_color_canMove); break;
		case 1: setRGBA(tile_color_canNotMove); break;
		case 2: setRGBA(tile_color_end); break;
		}
		float x = offMt.x + MapTileWidth * (i % MapTileNumX);
		float y = offMt.y + MapTileHeight * (i / MapTileNumX);
		fillRect(x, y, MapTileWidth, MapTileHeight);
		setRGBA(0, 0, 0, 1);
		drawRect(x + 2, y + 2, MapTileWidth - 4, MapTileHeight - 4);
	}


	hero->applyJump(movement, dt);
	
	if (getKeyDown() & keyboard_space) // 윗점프
	{
		
		hero->jump();
	}

	if (getKeyDown() & keyboard_down) // 아래점프
	{
		iPoint jumpVector = iPointMake(hero->getPosition().x, hero->getPosition().y + 1);
		// 왠지 화면밖을 나가는거 예외처리 해야할듯함 #bug
		hero->setPosition(jumpVector);
	}

	uint32 keyStat = 0;
	uint32 keyDown = 0;
	if (hero->behave != Behave_meleeAttack)
	{
		keyStat = getKeyStat();
		keyDown = getKeyDown();
	}
	iPoint v = iPointZero;
	Behave be;
	if (keyStat & keyboard_left) v.x = -1;
	else if (keyStat & keyboard_right) v.x = 1;
	//if (keyStat & keyboard_up) v.y = -1;
	else if (keyStat & keyboard_down) v.y = 1;


	if (keyDown & keyboard_num1)
	{
		printf("num1\n");
		be = Behave_meleeAttack;

		hero->Skill1();
	}

	else if (keyDown & keyboard_space)
		be = Behave_jumpAndFall;
	else if (keyDown & keyboard_down)
		be = Behave_idle;
	else if (keyDown & keyboard_up)
		be = Behave_jumpAndFall;
	else
		be = (v == iPointZero ? Behave_idle : Behave_move);
	int dir = hero->direction;
	if (v.x < 0) dir = 0;
	else if (v.x > 0) dir = 1;


	if (hero->behave != Behave_meleeAttack && hero->behave != Behave_jumpAndFall)
		hero->setBehave(be, dir);

	float minX, maxX, minY, maxY;
	if (v != iPointZero)
	{
		v /= iPointLength(v);
		iPoint mp = v * (hero->getMovement() * dt);
		hero->move(mp + movement, maptile);

		minX = devSize.width * 0.333333f;
		maxX = devSize.width * 0.666667f;
		minY = devSize.height * 0.333333f;
		maxY = devSize.height * 0.666667f;
	}
	else// if(v == iPointZero)
	{
		hero->move(movement * 3, maptile);

		minX = devSize.width / 2;
		maxX = devSize.width / 2;
		minY = devSize.height / 2;
		maxY = devSize.height / 2;
	}

	iPoint vp = offMt + hero->getPosition();
	if (vp.x < minX)
	{
		// 왼쪽으로 넘어갔을 경우
		offMt.x += (minX - vp.x) *dt;
		if (offMt.x > 0)
			offMt.x = 0;
	}
	else if (vp.x > maxX)
	{
		// 오른쪽으로 넘어갔을 경우
		offMt.x += (maxX - vp.x) * dt;
		if (offMt.x < devSize.width - MapTileWidth * MapTileNumX)
			offMt.x = devSize.width - MapTileWidth * MapTileNumX;
	}
	if (vp.y < minY)
	{
		// 위로 넘어갔을 경우
		offMt.y += (minY - vp.y) * dt;
		if (offMt.y > 0)
			offMt.y = 0;
	}
	else if (vp.y > maxY)
	{
		// 아래로 넘어갔을 경우
		offMt.y += (maxY - vp.y) * dt;
		if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
			offMt.y = devSize.height - MapTileHeight * MapTileNumY;
	}

	{ // paint Orc
		
		for (int i = 0; i < orc_Num; i++)
		{
			orcBehave orcBehave;
			if (orcs[i]->getHp() < 1) // Orc의 체력이 1미만이면 Death
			{
				orcBehave = orcBehave_death;
			}

		
			orcs[i]->r += orcs[i]->rValue * (i + 1);

			float rateOrcV = _sin(orcs[i]->r);

			float orcDir = 0;
		
			setRGBA(1, 1, 1, 1);
			orcs[i]->paint(dt, offMt);
			orcs[i]->setMovement(100);
			iPoint orcMovement = iPointMake(0, 1) * powGravity * dt;
			iPoint orcV = iPointMake(rateOrcV, 0);
			
			iPoint orcmp = orcV * (orc->getMovement() * dt);

			if (orcV != iPointZero)
			{
				orcBehave = orcBehave_move;

				if (orcV.x > 0)
					orcDir = 1;
				else
					orcDir = 0;

			}

			if (orcs[i]->behave != Behave_meleeAttack && orcs[i]->behave != Behave_jumpAndFall)
				orcs[i]->setBehave(orcBehave, orcDir);
			//printf("orcDt: %f\n", orcDt);

			orcs[i]->move(orcmp + orcMovement, maptile);

			//OrcDt += 1.0f;
		}
	}

	{ // paint Player
		setRGBA(1, 1, 1, 1);
		hero->paint(dt, offMt);

	}

#if _DEBUG
	//hitbox orc
	drawRect((orc->getPosition().x - orc->getSize().width / 2) + offMt.x, (orc->getPosition().y - orc->getSize().height) + offMt.y, orc->getSize().width, orc->getSize().height);

#endif
#if _DEBUG
	//hitbox player
	drawRect((hero->getPosition().x - hero->getSize().width / 2) + offMt.x,
		(hero->getPosition().y - hero->getSize().height) + offMt.y, hero->getSize().width, hero->getSize().height);
#endif



	drawPopPlayerUI(dt);
	showPopPlayerUI(true);

	drawPopMenuUI(dt);

}





void keyStage(iKeyState stat, iPoint point)
{
	if (keyPopPlayerUI(stat, point))
		return;

}




//----------------PopPlayerUI------------------------//

iPopup* PopPlayerUI;
iImage** PopPlayerUIImgs;
Texture* Poptex;

//const char* slotString[5] = { "Name", "HP", "MP", "Stamina", "Menu" };

void createPopPlayerUI()
{
	iPopup* pop = new iPopup(iPopupStyleNone);
	iGraphics* g = iGraphics::instance();
	iImage* img = new iImage();
	iSize size = iSizeMake(devSize.width, devSize.height); // 크기를 화면크기랑 동일하게 사용자의 화면을 그래도 덮는 UI Layer

	PopPlayerUIImgs = (iImage**)malloc(sizeof(iImage*) * 5);


	// Stage Title
	{
		g->init(size);
		setStringRGBA(0, 0, 0, 1);
		setRGBA(1, 1, 1, 0);// alpha값은 0 투명한 사이즈의 화면크기의 상자를 만드는거니까
		g->fillRect(0, 0, devSize.width, devSize.height);
		g->drawString(devSize.width / 2, 10, TOP | LEFT, "Stage");

		Poptex = g->getTexture();
		img->addObject(Poptex);
		freeImage(Poptex);

		//PopPlayerUIImgs[0] = img;
		pop->addObject(img);

	}
	// Stage Menu
	{
		iImage* menuBtn = new iImage();
		Texture* menuBtnTex;
		iSize menuSize = iSizeMake(200, 100);
		g->init(menuSize);
		setRGBA(0, 0, 1, 1);
		g->fillRect(0, 0, menuSize.width, menuSize.height);
		g->drawString(menuSize.width / 2, menuSize.height / 2, HCENTER | VCENTER, "Menu");
		
		menuBtnTex = g->getTexture();
		menuBtn->addObject(menuBtnTex);
		freeImage(menuBtnTex);

		menuBtn->position =iPointMake(devSize.width - menuSize.width, 10);
		PopPlayerUIImgs[0] = menuBtn;
		pop->addObject(menuBtn);

	}

	// PlayerInfo // 나중에 반복문으로 리팩터링 해야할 부분 #refactoring
	{
		iImage* playerName = new iImage();
		iImage* playerHP = new iImage();
		iImage* playerMP = new iImage();
		iImage* playerStamina = new iImage();
	
		Texture* infoTex;
		iSize infoSize = iSizeMake(200, 100);
		setRGBA(0, 1, 0, 1);

		g->init(infoSize);
		g->fillRect(0, 0, infoSize.width, infoSize.height);
		g->drawString(infoSize.width / 2, infoSize.height / 2, HCENTER | VCENTER, "Portrait");
		
		infoTex = g->getTexture();
		playerName->addObject(infoTex);
		freeImage(infoTex);

		playerName->position = iPointMake(0, 10);

		PopPlayerUIImgs[1] = playerName;
		pop->addObject(playerName);

	
		infoSize = iSizeMake(200, 50);
		setRGBA(1, 0, 0, 1);

		g->init(infoSize);
		g->fillRect(0, 0, infoSize.width, infoSize.height);
		g->drawString(infoSize.width / 2, infoSize.height / 2, HCENTER | VCENTER, "HP");

		infoTex = g->getTexture();
		playerHP->addObject(infoTex);
		freeImage(infoTex);

		playerHP->position = iPointMake(0, 110);

		PopPlayerUIImgs[2] = playerHP;
		pop->addObject(playerHP);
		

		setRGBA(0, 0, 1, 1);
		g->init(infoSize);
		g->fillRect(0, 0, infoSize.width, infoSize.height);
		g->drawString(infoSize.width / 2, infoSize.height / 2, HCENTER | VCENTER, "MP");

		infoTex = g->getTexture();
		playerMP->addObject(infoTex);
		freeImage(infoTex);

		playerMP->position = iPointMake(0, 160);

		PopPlayerUIImgs[3] = playerMP;
		pop->addObject(playerMP);

		setRGBA(1, 1, 0, 1);

		g->init(infoSize);
		g->fillRect(0, 0, infoSize.width, infoSize.height);
		g->drawString(infoSize.width / 2, infoSize.height / 2, HCENTER | VCENTER, "Stamina");

		infoTex = g->getTexture();
		playerStamina->addObject(infoTex);
		freeImage(infoTex);

		playerStamina->position = iPointMake(0, 210);

		PopPlayerUIImgs[4] = playerStamina;
		pop->addObject(playerStamina);







	}


	pop->openPosition = iPointZero;
	pop->closePosition = iPointZero;

	PopPlayerUI = pop;
	setRGBA(1, 1, 1, 1);

}

void freePopPlayerUI()
{
	delete PopPlayerUI;
}

void drawPopPlayerUI(float dt)
{
	PopPlayerUI->paint(dt);
}

bool keyPopPlayerUI(iKeyState stat, iPoint point)
{

	int i, j = -1;

	switch (stat)
	{
		case iKeyStateBegan:
			i = PopPlayerUI->selected;

			if (i == -1)
				break;

			else if(i == 0)
			{
				printf("selected = %d\n", i);

				showPopMenuUI(true);
			}

		
			else
				printf("seletecd = %d\n", i);
			break;
	
		case iKeyStateMoved:

			for (i = 0; i < 5; i++)
			{
				if (containPoint(point, PopPlayerUIImgs[i]->touchRect(PopPlayerUI->closePosition)))
				{
					j = i;
					break;
				}
			}
			PopPlayerUI->selected = j;
			break;
	
		case iKeyStateEnded:

			break;
	
	}

	return true;
}

void showPopPlayerUI(bool show)
{
	PopPlayerUI->show(show);
}

//--------------PopMenuUI---------------------/

iPopup* PopMenuUI;
iImage** PopMenuUIImgs;

const char* btnString[3] = { "Rusume Game", "Settings", "Game Quit" };

void createPopMenuUI()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(500, 500);

	PopMenuUIImgs = (iImage**)malloc(sizeof(iImage*) * 3);

	// Background //
	{
		iImage* img = new iImage();
		Texture* tex;
		g->init(size);
		setStringRGBA(0, 0, 0, 1);
		setRGBA(1, 0, 1, 1);
		g->fillRect(0, 0, size.width, size.height);

		tex = g->getTexture();
		img->addObject(tex);
		freeImage(tex);
		img->position = iPointMake(0,0);

		pop->addObject(img);
	}

	// buttons
	{
		setRGBA(0, 1, 1, 1);
		setStringRGBA(0, 0, 0, 1);
		setStringSize(20);
		
		iSize btnSize = iSizeMake(300, 30);
		
		for(int i= 0; i<3; i++)
		{
			Texture* tex;
			iImage* btnImg = new iImage();
			
			g->init(btnSize);
			g->fillRect(0,0,btnSize.width, btnSize.height);
			g->drawString(btnSize.width / 2, btnSize.height / 2, HCENTER | VCENTER, btnString[i]);

			tex = g->getTexture();
			btnImg->addObject(tex);
			freeImage(tex);

			btnImg->position = iPointMake((size.width - btnSize.width) /2,i*100 +15);
			PopMenuUIImgs[i] = btnImg;
			pop->addObject(btnImg);
		
		}
		
	}


	// 메뉴창에 간단하게 게임 설명(목표) 넣는 부분




	
	pop->openPosition = iPointMake((devSize.width - size.width) / 2,(devSize.height - size.height)/2);
	pop->closePosition = pop->openPosition;

	PopMenuUI = pop;

	setRGBA(1, 1, 1, 1);
	
}

void freePopMenuUI()
{
	delete PopMenuUI;

	free(PopMenuUIImgs);
}

void drawPopMenuUI(float dt)
{
	PopMenuUI->paint(dt);
}

bool keyPopMenuUI(iKeyState stat, iPoint point)
{
	return true;
}

void showPopMenuUI(bool show)
{
	PopMenuUI->show(show);
}






