#pragma once

#include "iStd.h"

#define gs_intro	0
#define	gs_menu		1
#define	gs_stage	2
#define gs_endStage 3

#define gs_ending	8

#define gs_trailer  9
#define	gs_none		0xFF

extern int gameState;

typedef void(*METHOD)();
void setLoading(int newGameState, METHOD free, METHOD load);

void drawLoading(float dt);
bool keyLoading(iKeyState stat, iPoint point);