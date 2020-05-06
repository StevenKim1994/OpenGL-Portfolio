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