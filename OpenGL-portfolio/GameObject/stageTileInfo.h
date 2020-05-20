#pragma once

#include "iStd.h"


struct MapTile
{
	uint8 attr; // 0 : 이동가능 , 1 : 사다리 99: 이동불가 5: 맵의 끝
	uint8 imgIndex;
};

#define canMove 01
#define endofTile 99
#define canNotMove 99
#define deadZone 44

#define nextStagePortal 77

#define MapTileNumX 80
#define MapTileNumY 30
#define MapTileWidth 32
#define MapTileHeight 32

#define tile_color_canMove 1,1,1,0
#define tile_color_canNotMove 1,0,1,1
#define tile_color_ladder 1,0,0,1
#define tile_color_end 0,1,1,1

#define natureSpeed 100
#define powGravity 200
#define powJump 300

#define MapCharWidth 16
#define MapCharHeight 16
#define MapCharMovement 200 // 맵 기본 캐릭터들 이동속도
#define MapCharSpeed 10 // 맵 기본 캐릭터들 공격속도

#define hero_color 0, 0, 1, 1



