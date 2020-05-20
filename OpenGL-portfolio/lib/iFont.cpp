#pragma once

#include "iFont.h"
#include "iStd.h"


iFont* font;

void loadFont()
{
	const char* str = "0123456789";

	font = (iFont*)malloc(sizeof(iFont) * 1);
	font->s = 64;
	int num = strlen(str);

	font->tex = (Texture**)malloc(sizeof(Texture*) * num);

	setStringSize(60);
	setStringRGBA(1, 1, 1, 1); // 흰색으로 해야 범용적으로 모든 색을 곱하였을때 그 색이 나온다
	setStringBorder(0);


	iGraphics* g = iGraphics::instance();
	iSize size = iSizeMake(64, 64);

	g->init(size);

	for (int i = 0; i < num; i++)
	{
		g->init(size);
	
		char s[2] = { str[i], 0 };
		g->drawString(size.width / 2, size.height, VCENTER | HCENTER, s);

		font->tex[i] = g->getTexture();
	}

}

void freeFont()
{
	for (int i = 0; i < 10; i++)
		freeImage(font->tex[i]);
	free(font);
}

void drawFont(int x, int y, int anc, const char* szFormat,...)
{
	va_list args;
	va_start(args, szFormat);

	char szText[1024];
	_vsnprintf(szText, sizeof(szText), szFormat, args);
	va_end(args);


	int len = strlen(szText);
	for (int i = 0; i < len; i++)
	{
		drawImage(font->tex[szText[i] - '0'], x, y, TOP | LEFT);
		x += font->s;
	}
}
