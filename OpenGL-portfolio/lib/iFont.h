#pragma once

#include "iStd.h"

struct iFont
{
	Texture** tex;
	int s;
};

void loadFont();
void freeFont();
void drawFont(int x, int y, int anc, const char* szFormat,...);