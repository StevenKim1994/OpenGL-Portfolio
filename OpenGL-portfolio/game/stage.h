#pragma once

#include "iStd.h"

#include "sceneManager.h"



void loadStage();
void freeStage();
void drawStage(float dt);
void keyStage(iKeyState stat, iPoint point);

struct MapTile
{
	uint8 attr; // 0 : 이동가능 , 1 : 사다리 99: 이동불가
	uint8 imgIndex;
};

#define MapTileNumX 30
#define MapTileNumY 30
#define MapTileWidth 64
#define MapTileHeight 64

#define title_color_canMove 1,1,1,1
#define title_color_canNotMove 1,0,1,1
#define title_color_ladder 1,0,0,1
#define title_color_end 0,1,1,1

#define natureSpeed 100
#define powGravity 200
#define powJump 500




