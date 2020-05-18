#pragma once
#include "stage.h"
#include "stageTileInfo.h"
#include "Monster.h"
#include "Player.h"
#include "Orc.h"


int tiles[MapTileNumX * MapTileNumY] = {
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,03,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,03,01,03,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,99,99,99,99,99,99,99,99,99,99,99,99,99,99,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,99,02,02,02,02,02,02,02,02,02,02,02,02,02,02,99,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,99,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,99,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,

};



#define ON_HITBOX 0

Player* hero;
MapTile* maptile;
iPoint offMt;
iPoint vp;

Monster** orcs;
Orc* orc;
Texture* bgTex; // bacckground Image

#define orc_Num 3 // 맵에 존재하는 오크의 최대 마리수

Texture* tile_ground;
Texture* tile_inGround;
Texture* stoneBlock_tex;

Texture* texFboStage;
iShortestPath* sp;
bool mouseMove = false;

void loadStage()
{
	texFboStage = createTexture(devSize.width, devSize.height);

	iGraphics* g = iGraphics::instance();

	tile_ground = createImage("assets/stage/tileset/ground.png");
	stoneBlock_tex = createImage("assets/stage/tileset/stoneBlock.png");
	tile_inGround = createImage("assets/stage/tileset/inGround.png");
	setRGBA(1, 1, 1, 1);
	igImage* ig = g->createIgImage("assets/stage/background.png");
	iSize bgSize = iSizeMake(g->getIgImageWidth(ig) - 640, g->getIgImageHeight(ig) - 360);
	g->init(bgSize);
	g->drawImage(ig, 0, 0, 0.666f, 0.666f, TOP | LEFT);
	bgTex = g->getTexture();



	int i, num = MapTileNumX * MapTileNumY;
	maptile = (MapTile*)malloc(sizeof(MapTile) * num);
	for (i = 0; i < num; i++)
	{
		MapTile* t = &maptile[i];
		t->attr = tiles[i];
		//t->imgIndex;
	}

	hero = new Player(); // 플레이어 캐릭터 생성

	hero->setSize(iSizeMake(PlayerWidth, PlayerHeight));

	hero->setMovement(MapCharMovement);
	hero->setPosition(iPointMake(MapTileWidth *30,MapTileHeight *45));
	//hero->setTargetPosition(hero->getPosition());
	offMt = hero->getPosition();// iPointZero;
	// camera positioning
	offMt = iPointMake(-760, -880+500);



	orcs = (Monster**)malloc(sizeof(Monster) * orc_Num);

	for (int i = 0; i < orc_Num; i++) // 맵에 오크 생성
	{
		orc = new Orc();
		orc->setPosition(iPointMake(MapTileWidth * 30 + (i * MapTileWidth), MapTileHeight*45));
		orc->alive = true;
		orcs[i] = orc;
	}


	sp = new iShortestPath();
	sp->init(tiles, MapTileNumX, MapTileNumY);

	createPopPlayerUI();
	createPopMenuUI();
	createPopQuitAnswerUI();


	
}

void freeStage()
{
	freeImage(texFboStage);

	freePopPlayerUI();
	freePopMenuUI();
	freePopQuitAnswerUI();
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
	fbo->bind(texFboStage);////////////////////////////////////////////////////////////////////////////////

	iPoint movement = iPointMake(0, 1) * powGravity * dt;

	drawImage(bgTex, 0, 0, TOP | LEFT); // background


	int i, num = MapTileNumX * MapTileNumY;
	for (i = 0; i < num; i++)
	{
		MapTile* t = &maptile[i];

		float x = offMt.x + MapTileWidth * (i % MapTileNumX);
		float y = offMt.y + MapTileHeight * (i / MapTileNumX);
		
		switch(t->attr)
		{
			case 0: break;
			case canNotMove: setRGBA(1, 1, 1, 1); drawImage(tile_ground, x, y, TOP | LEFT); break;
			case 02: setRGBA(1, 1, 1, 1); drawImage(tile_inGround, x, y, TOP | LEFT); break;
			case 03: setRGBA(1, 1, 1, 1); drawImage(stoneBlock_tex, x, y, TOP | LEFT); break;

		}
		
		setRGBA(0, 0, 0, 1);

		if(t->attr != 0)
			drawRect(x + 2, y + 2, MapTileWidth - 4, MapTileHeight - 4);
	}

	uint32 keyStat = 0;
	uint32 keyDown = 0;

	hero->applyJump(movement, dt);
	
	if (getKeyDown() & keyboard_space) // 윗점프
	{
		
		hero->jump();
		if (hero->behave != PlayerBehave_meleeAttack)
		{
			keyStat = getKeyStat();
			keyDown = getKeyDown();
		}
		iPoint v = iPointZero;
		PlayerBehave be;
		if (keyStat & keyboard_left) v.x = -1;
		else if (keyStat & keyboard_right) v.x = 1;
		//if (keyStat & keyboard_up) v.y = -1;
		else if (keyStat & keyboard_down) v.y = 1;

	}

	if (getKeyDown() & keyboard_down) // 아래점프
	{		
		iPoint jumpVector = iPointMake(hero->getPosition().x, hero->getPosition().y + 1);
		// 왠지 화면밖을 나가는거 예외처리 해야할듯함 #bug
		
		hero->setPosition(jumpVector);
	}

	if (hero->behave != PlayerBehave_meleeAttack)
	{
		keyStat = getKeyStat();
		keyDown = getKeyDown();
	}
	iPoint v = iPointZero;
	PlayerBehave be;
	if (keyStat & keyboard_left) v.x = -1;
	else if (keyStat & keyboard_right) v.x = 1;
	//if (keyStat & keyboard_up) v.y = -1;
	else if (keyStat & keyboard_down) v.y = 1;


	


	
	if (mouseMove) // 마우스 입력이 있을때
	{
		if( hero->moveForMouse(dt) )
			mouseMove = false;

		if (v != iPointZero)
		{
			mouseMove = false;
			hero->setTargetPosition(hero->getPosition());
			hero->pathNum = hero->pathIndex;
		}
	}
	else // 키보드 입력일때
	{

		if (keyDown & keyboard_num1)
		{

			printf("num1\n");
			be = PlayerBehave_meleeAttack;
			hero->Skill1(orcs, orc_Num);
			

			zoomCamera(hero->getPosition() + offMt, 1.5);
			shakeCamera(30);

		}

		
		else if (keyDown & keyboard_space)
			be = PlayerBehave_jumpAndFall;
		else if (keyDown & keyboard_down)
			be = PlayerBehave_idle;
		else if (keyDown & keyboard_up)
			be = PlayerBehave_jumpAndFall;
		else
			be = (v == iPointZero ? PlayerBehave_idle : PlayerBehave_move);
		int dir = hero->direction;
		if (v.x < 0) dir = 0;
		else if (v.x > 0) dir = 1;

	

		if (hero->behave != PlayerBehave_meleeAttack && hero->behave != PlayerBehave_jumpAndFall)
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
	}

	{ // paint Orc
		
		for (int i = 0; i < orc_Num; i++)
		{
			EnermyBehave orcBehave;
			if (orcs[i]->getHp() < 1) // Orc의 체력이 1미만이면 Death
			{
				orcBehave = EnermyBehave_death;
				orcs[i]->alive = false;
				hero->kill++;
			}


			if (orcs[i]->alive == true)
			{
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
					orcBehave = EnermyBehave_move;

					if (orcV.x > 0)
						orcDir = 1;
					else
						orcDir = 0;

				}

				if (orcs[i]->behave != PlayerBehave_meleeAttack && orcs[i]->behave != PlayerBehave_jumpAndFall)
					orcs[i]->setBehave(orcBehave, orcDir);
				//printf("orcDt: %f\n", orcDt);

				orcs[i]->move(orcmp + orcMovement, maptile);

				//OrcDt += 1.0f;
			}
		}
	}

	{ // paint Player
		setRGBA(1, 1, 1, 1);
		hero->paint(dt, offMt);


	}
	setRGBA(1, 1, 1, 1);

#if _DEBUG
	//hitbox orc
	for(int i = 0; i<orc_Num; i++)
		drawRect((orcs[i]->getPosition().x - orcs[i]->getSize().width / 2) + offMt.x, (orcs[i]->getPosition().y - orcs[i]->getSize().height) + offMt.y, orcs[i]->getSize().width, orcs[i]->getSize().height);

#endif
#if _DEBUG
	//hitbox player
	drawRect((hero->getPosition().x - hero->getSize().width / 2) + offMt.x,
		(hero->getPosition().y - hero->getSize().height) + offMt.y, hero->getSize().width, hero->getSize().height);
#endif

	fbo->unbind();////////////////////////////////////////////////////////////////////////////////
	Texture* tex = texFboStage;

	showCamera(tex, dt);

	drawPopPlayerUI(dt);
	showPopPlayerUI(true);
	drawPopMenuUI(dt);
	drawPopQuitAnswerUI(dt);
	

}





void keyStage(iKeyState stat, iPoint point)
{
	

	if(keyPopQuitAnswerUI(stat, point))
		return;

	if (keyPopMenuUI(stat, point))
		return;
	
	if (keyPopPlayerUI(stat, point))
		return;

		
	if (stat == iKeyStateBegan)
	{
		printf("!!\n");
		
		
		int sx = hero->getPosition().x;
		sx /= MapTileWidth;

		int sy = hero->getPosition().y;
		sy /= MapTileHeight;

		int ex = point.x - offMt.x;
		ex /= MapTileWidth;

		int ey = point.y - offMt.y;
		ey /= MapTileHeight;

		printf("sx : %d sy : %d  ex : %d ey : %d\n", sx, sy, ex, ey);
		printf("begin :%d dest : %d\n", sy * MapTileNumX+ sx, ey * MapTileNumX + ex);
		
		
		if (sy != ey) // 횡스크롤 게임이므로 최단경로 고려할떄 같은 가로위치일떄만 고려함
			return;

		sp->dijkstra(sy * MapTileNumX + sx, ey * MapTileNumX + ex, hero->path, hero->pathNum);
		

		for(int i = 0 ; i < hero->pathNum; i++)
			printf("중복제거전! %d ,%d\n", i, hero->path[i]);
		sp->removeDuplicate(hero->path, hero->pathNum);
		hero->setTargetPosition(hero->getPosition());
		hero->pathIndex = 1;

		for (int i = 0; i < hero->pathNum; i++)
			printf("%d ,%d\n", i, hero->path[i]);
		mouseMove = true;
	}


}




//----------------PopPlayerUI------------------------//

iPopup* PopPlayerUI;
iImage** PopPlayerUIImgs;
Texture* Poptex;
iPopup* PopMenuUI;

//const char* slotString[5] = { "Name", "HP", "MP", "Stamina", "Menu" };

const char* mapTitle[1] = { "Rock Mountain" };
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
		g->drawString(devSize.width / 2, 10, HCENTER | VCENTER, "- Stage -");
		g->drawString(devSize.width / 2, 35, HCENTER|VCENTER, mapTitle[0]);
		g->drawString(devSize.width / 2, 65, HCENTER | VCENTER, "KILL: %d", hero->kill);
		Poptex = g->getTexture();
		img->addObject(Poptex);
		freeImage(Poptex);

	
		
		pop->addObject(img);

	}

	{ // 미니맵
		setRGBA(1, 1, 0, 1);
		setStringSize(10);
		iSize mapsize = iSizeMake(200, 200);
		g->init(mapsize);
		g->fillRect(0, 0, mapsize.width, mapsize.height);
		g->drawString(mapsize.width / 2, mapsize.height / 2, HCENTER | VCENTER, "Minimap position");
		Texture* minimapTex = g->getTexture();
		iImage* minimap = new iImage();
		minimap->addObject(minimapTex);
		minimap->position = iPointMake(devSize.width - mapsize.width, 60);
		pop->addObject(minimap);

	}

	
	// Stage Menu
	{
		setStringSize(30);
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

				if (PopMenuUI->bShow == false)
					showPopMenuUI(true);

				else
					showPopMenuUI(false);
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

//iPopup* PopMenuUI; PlayerUI 위에 선언해놨음.
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

	setRGBA(1, 1, 1, 1);

	PopMenuUI = pop;

	
}

void freePopMenuUI()
{
	delete PopMenuUI;

}

void drawPopMenuUI(float dt)
{
	PopMenuUI->paint(dt);
}

bool keyPopMenuUI(iKeyState stat, iPoint point)
{
	if (PopMenuUI->bShow == false)
		return false;

	if (PopMenuUI->stat != iPopupStatProc)
		return true;

	int i, j = -1;

	switch (stat)
	{
	case iKeyStateBegan:
	{
		i = PopMenuUI->selected;

		if (i == -1)
			break;

		else if (i == 0)
		{
			printf("selected = %d\n", i);
			PopMenuUI->show(false);

		}


		else if (i == 1)
		{

		}

		else if (i == 2)
		{
			printf("QuitANSWER?\n");
			showPopQuitAnswerUI(true);
		}

		printf("seletecd = %d\n", i);
		break;
	}

	case iKeyStateMoved:
	{
	
		for (i = 0; i < 3; i++)
		{
			if (containPoint(point, PopMenuUIImgs[i]->touchRect(PopMenuUI->closePosition)))
			{
				j = i;
				break;
			}
		}
		PopMenuUI->selected = j;
		printf("seletecd = %d\n", PopMenuUI->selected);
		break;
	}
	case iKeyStateEnded:
	{

		break;
	}

	}

	return true;
}

void showPopMenuUI(bool show)
{
	PopMenuUI->show(show);
}



//----------------------PopQuitAnswerUI------------------------//

iPopup* PopQuitAnswerUI;
iImage** PopQuitAnswerUIBtn;
// 0 : yes,  1 : no
const char* btnUISlot[2] = { "Okay", "No" };
void createPopQuitAnswerUI()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(500, 300);

	PopQuitAnswerUIBtn = (iImage**)malloc(sizeof(iImage*) * 2); // 0 : yes , 1 : no

	setStringBorder(0);
	setStringBorderRGBA(0, 0, 0, 1);
	setStringRGBA(0, 0, 0, 1);
	setStringSize(50);


 
	{ // background
		igImage* ig = g->createIgImage("assets/menu/popBg.png");
		size = iSizeMake(g->getIgImageWidth(ig) * 2.5, g->getIgImageHeight(ig) * 2.5);
		g->init(size);
		g->drawImage(ig, 0, 0, 2.5, 2.5, TOP | LEFT);
		g->drawString(size.width / 2, size.height /2 -175, VCENTER | HCENTER, "Do you want exit?");
		Texture* bgTex;

		bgTex = g->getTexture();

		iImage* bgImg = new iImage();
		bgImg->position = iPointMake(devSize.width / 2, devSize.height / 2);

		bgImg->addObject(bgTex);
		freeImage(bgTex);

		pop->addObject(bgImg);

	}

	for (int i = 0; i < 2; i++)
	{
		iImage* answerBtn = new iImage();
		Texture* btnTex;

		for (int j = 0; j < 2; j++)
		{
			if (j == 0) // btnOff
			{
				setRGBA(1, 1, 1, 1);
				setStringSize(30);
				igImage* answerBtn = g->createIgImage("assets/menu/BTN0.png");
				iSize btnSize = iSizeMake(g->getIgImageWidth(answerBtn), g->getIgImageHeight(answerBtn));
				g->init(btnSize);
				g->drawImage(answerBtn, 0, 0, 1, 1, TOP | LEFT);
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnUISlot[i]);
				btnTex = g->getTexture();
			}

			else // btnOn
			{
				setRGBA(1, 0, 0, 1);
				setStringSize(30);
				igImage* answerBtn = g->createIgImage("assets/menu/BTN0.png");
				iSize btnSize = iSizeMake(g->getIgImageWidth(answerBtn), g->getIgImageHeight(answerBtn));
				g->init(btnSize);
				g->drawImage(answerBtn, 0, 0, 1, 1, TOP | LEFT);
				g->drawString(btnSize.width / 2, btnSize.height / 2, VCENTER | HCENTER, btnUISlot[i]);
				btnTex = g->getTexture();
			}

			answerBtn->addObject(btnTex);
			answerBtn->position = iPointMake(devSize.width/2 * (i+1)+ 150, size.height + 10);
			freeImage(btnTex);
		}
		
		pop->addObject(answerBtn);

		PopQuitAnswerUIBtn[i] = answerBtn;

	}

	pop->openPosition = iPointMake(devSize.width /2 - size.width -100 , devSize.height/2 -size.height);
	pop->closePosition = pop->openPosition;
	PopQuitAnswerUI = pop;

}

void freePopQuitAnswerUI()
{
	delete PopQuitAnswerUI;
}

void drawPopQuitAnswerUI(float dt)
{
	PopQuitAnswerUI->paint(dt);
}

bool keyPopQuitAnswerUI(iKeyState stat, iPoint point)
{
	if (PopQuitAnswerUI->bShow == false)
		return false;

	if (PopQuitAnswerUI->stat != iPopupStatProc)
		return true;

	int i, j = -1;

	switch (stat)
	{
		case iKeyStateBegan:
		{
			i = PopQuitAnswerUI->selected;

			if (i == -1)
				break;

			if (i == 0)
			{
				extern bool runWnd;
				runWnd = false;

			}
			else if (i == 1)
			{
				PopQuitAnswerUI->show(false);
			}
			break;
		}

		case iKeyStateMoved :
		{
			for (i = 0; i < 2; i++)
			{
				if (containPoint(point, PopQuitAnswerUIBtn[i]->touchRect(PopQuitAnswerUI->closePosition)))
				{
					j = i;
					break;
				}
			}
			PopQuitAnswerUI->selected = j;
			break;
		}

		case iKeyStateEnded:
			break;
	}

	return true;
}

void showPopQuitAnswerUI(bool show)
{
	PopQuitAnswerUI->show(show);
}






