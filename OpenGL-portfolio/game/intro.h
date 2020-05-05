#pragma once
#include "iStd.h"

void loadIntro();
void freeIntro();
void drawIntro(float dt);
void keyIntro(iKeyState stat, iPoint point);


// ------------ Title Popup ---------------/

void createTitle();
void freeTitle();
void drawTitle(float dt);
void keyTitle();
void showTitle(bool show);