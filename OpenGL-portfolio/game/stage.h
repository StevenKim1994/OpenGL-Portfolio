#pragma once

#include "iStd.h"

#include "sceneManager.h"



void loadStage();
void freeStage();
void drawStage(float dt);
void keyStage(iKeyState stat, iPoint point);





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

#define MapCharWidth 30
#define MapCharHeight 30
#define MapCharSpeed 200

#define hero_color 0,0,1,1


// 여기에 플레이어의 체력, 게임 플레이상의 UI 출력해야함 
//-------------popPlayerUI--------------------//
void createPopPlayerUI();
void freePopPlayerUI();
void drawPopPlayerUI(float dt);
bool keyPopPlayerUI(iKeyState stat, iPoint point);
void showPopPlayerUI(bool show);






