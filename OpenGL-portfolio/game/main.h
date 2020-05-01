#pragma once
#include "iStd.h"

#include "../resource.h"

extern iPoint cursor;
void loadCursor();
void freeCursor();
void drawCursor(float dt);
bool updateCursor(bool inClient);

extern bool isFullscreen;
void goFullscreen();

extern int win_border_width, win_border_height;
void enforceResolution(int edge, RECT& rect, int win_border_width, int win_border_height);

#define DEV_MIN_RATE 1/3.