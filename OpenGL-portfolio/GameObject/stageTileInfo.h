#pragma once

#include "iStd.h"


struct MapTile
{
	uint8 attr; // 0 : 이동가능 , 1 : 사다리 5: 이동불가 5: 맵의 끝
	uint8 imgIndex;
};

#define canMove 0
#define ladder 1
#define endofTile 99
#define canNotMove 5

#define MapTileNumX 30
#define MapTileNumY 30
#define MapTileWidth 60
#define MapTileHeight 60

#define tile_color_canMove 1,1,1,1
#define tile_color_canNotMove 1,0,1,1
#define tile_color_ladder 1,0,0,1
#define tile_color_end 0,1,1,1

#define natureSpeed 100
#define powGravity 200
#define powJump 500

//MapTile* mt = (MapTile*)malloc(sizeof(MapTile) * MapTileNumX* MapTileNumY);