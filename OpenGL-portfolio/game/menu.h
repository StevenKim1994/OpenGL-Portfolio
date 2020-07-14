#pragma once
#include "iStd.h"

void loadMenu();
void freeMenu();
void drawMenu(float dt);
void keyMenu(iKeyState stat, iPoint point);

//---------PopMenuBtn----------------------//
void createPopMenuBtn();
void freePopMenuBtn();
void drawPopMenuBtn(float dt);
bool keyPopMenuBtn(iKeyState stat, iPoint point);
void showPopMenuBtn(bool show);


//---------PopSettings---------------------//
void createPopSettings();
void freePopSettings();
void drawPopSettings(float dt);
bool keyPopSettings(iKeyState stat, iPoint point);
void showPopSettings(bool show);


//---------PopQuitAnswer-------------------//
void createPopQuitAnswer();
void freePopQuitAnswer();
void drawPopQuitAnswer(float dt);
bool keyPopQuitAnswer(iKeyState stat, iPoint point);
void showPopQuitAnswer(bool show);
void drawPopQuitAnswerBefore(iPopup* me, iPoint p, float dt);


