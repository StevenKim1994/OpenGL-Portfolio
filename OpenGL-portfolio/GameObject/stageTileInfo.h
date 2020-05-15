#pragma once

#include "iStd.h"


struct MapTile
{
	uint8 attr; // 0 : 이동가능 , 1 : 사다리 99: 이동불가 5: 맵의 끝
	uint8 imgIndex;
};

#define canMove 0
#define ladder 1
#define endofTile 99
#define canNotMove 5
#define stoneBlock 3
#define inGround 2

#define MapTileNumX 100
#define MapTileNumY 50
#define MapTileWidth 48
#define MapTileHeight 38

#define tile_color_canMove 1,1,1,0
#define tile_color_canNotMove 1,0,1,1
#define tile_color_ladder 1,0,0,1
#define tile_color_end 0,1,1,1

#define natureSpeed 100
#define powGravity 200
#define powJump 300




