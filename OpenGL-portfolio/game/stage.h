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

#define canMove 0
#define ladder 1
#define endofTile 5
#define canNotMove 99

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


struct MapHero
{
	iPoint position;
	iSize size;
	float speed;

	iPoint jumpment;
	int jumpNum, _jumpNum;

	void move(iPoint movement);
	void jump();
	void applyJump(iPoint& movement, float dt);

};

#define MapCharWidth 30
#define MapCharHeight 30
#define MapCharSpeed 200

#define hero_color 0,0,1,1




