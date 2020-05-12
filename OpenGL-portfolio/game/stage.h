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



#define MapCharWidth 25
#define MapCharHeight 25
#define MapCharMovement 200 // 맵 기본 캐릭터들 이동속도
#define MapCharSpeed 10 // 맵 기본 캐릭터들 공격속도

#define hero_color 0, 0, 1, 1


//-------------PopPlayerUI----------------------//
void createPopPlayerUI();
void freePopPlayerUI();
void drawPopPlayerUI(float dt);
bool keyPopPlayerUI(iKeyState stat, iPoint point);
void showPopPlayerUI(bool show);
