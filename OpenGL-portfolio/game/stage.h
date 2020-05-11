#pragma once

#include "iStd.h"




void loadStage();
void freeStage();
void drawStage(float dt);
void keyStage(iKeyState stat, iPoint point);





// 여기에 플레이어의 체력, 게임 플레이상의 UI 출력해야함 
//-------------popPlayerUI--------------------//
void createPopPlayerUI();
void freePopPlayerUI();
void drawPopPlayerUI(float dt);
bool keyPopPlayerUI(iKeyState stat, iPoint point);
void showPopPlayerUI(bool show);


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

#define MapCharWidth 25
#define MapCharHeight 25
#define MapCharSpeed 200

#define hero_color 0, 0, 1, 1
