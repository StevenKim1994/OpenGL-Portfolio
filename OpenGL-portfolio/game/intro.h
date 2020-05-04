#pragma once
#include "iStd.h"

void loadIntro();
void freeIntro();
void drawIntro(float dt);
void keyIntro(iKeyState stat, iPoint point);



// ------------------------------------------------
//	Press Any Key PopUP
// ------------------------------------------------

void createPressPop();
void freePressPop();
void showPressPop(bool show);
void drawPressPop(float dt);
bool keyPressPop(iKeyState stat, iPoint point);
