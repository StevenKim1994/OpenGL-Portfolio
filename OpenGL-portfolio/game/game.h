#pragma once

#include "iStd.h"

void loadGame();
void freeGame();
void drawGame(float dt);
void keyGame(iKeyState stat, iPoint point); 

//---------PopQuitAnswer-------------------//
void createPopQuitAnswer();
void freePopQuitAnswer();
void drawPopQuitAnswer(float dt);
bool keyPopQuitAnswer(iKeyState stat, iPoint point);
void showPopQuitAnswer(bool show);
void drawPopQuitAnswerBefore(iPopup* me, iPoint p, float dt);
