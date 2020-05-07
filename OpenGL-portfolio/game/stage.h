#pragma once

#include "iStd.h"

#include "sceneManager.h"



void loadStage();
void freeStage();
void drawStage(float dt);
void keyStage(iKeyState stat, iPoint point);

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
#define MapTileWidth 64
#define MapTileHeight 64

#define tile_color_canMove 1,1,1,1
#define tile_color_canNotMove 1,0,1,1
#define tile_color_ladder 1,0,0,1
#define tile_color_end 0,1,1,1

#define natureSpeed 100
#define powGravity 200
#define powJump 500


// 한점에서 직선까지의 거리
float getDistanceLine0(iPoint p, iPoint sp, iPoint ep);
// 한점에서 선분까지의 거리
float getDistanceLine1(iPoint p, iPoint sp, iPoint ep);



struct MapHero
{
	
	iImage* idle;
	iImage* meleeAttack;
	iImage* moving;

	int state; // 0 : idle 1: attack 2: moving
	int direction;

	iPoint position;
	iSize size;
	float speed;

	iPoint jumpment;
	int jumpNum, _jumpNum;

	void move(iPoint movement);
	void jump();
	void applyJump(iPoint& movement, float dt);

	void idleMotion(iPoint v);//v는 바라보는 방향 벡터
	void meleeAttackMotion(int direction);


};

#define MapCharWidth 256
#define MapCharHeight 256
#define MapCharSpeed 200

#define hero_color 0,0,1,1


// 여기에 플레이어의 체력, 게임 플레이상의 UI 출력해야함 
//-------------popPlayerUI--------------------//
void createPopPlayerUI();
void freePopPlayerUI();
void drawPopPlayerUI(float dt);
bool keyPopPlayerUI(iKeyState stat, iPoint point);
void showPopPlayerUI(bool show);






