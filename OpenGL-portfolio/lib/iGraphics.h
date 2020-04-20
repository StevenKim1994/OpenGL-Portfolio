#pragma once
#include <windows.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

#include "iType.h"

typedef Image igImage;

ULONG_PTR startGdiplus();
void endGdiplus(ULONG_PTR gpToken);

wchar_t* utf8_to_utf16(const char* szFornat, ...);
char* utf16_to_utf8(const wchar_t* str);

void checkFontFamily(FontFamily* ff, int& style);

class iGraphics
{
private:
	iGraphics();

public:
	static iGraphics* instance();
	virtual ~iGraphics();

	void init(iSize size);
	void init(int width, int height);

	void setClip(int x, int y, int width, int height);
	void setClip(iRect rect);

	static igImage* createIgImage(const char* szFormat, ...);
	static void freeIgImage(igImage* img);
	static int getIgImageWidth(igImage* img);
	static int getIgImageHeight(igImage* img);

	void drawImage(igImage* img, float x, float y, int anc);
	void drawImage(igImage* img, float x, float y, float rx, float ry, int anc);
	void drawImage(igImage* img, int x, int y, int ix, int iy, int iw, int ih, int anc, float ratX, float ratY, int xyz, float degree, int reverse);
	
	void drawString(float x, float y, int anc, const char* szFormat, ...);

	void drawLine(iPoint sp, iPoint ep);
	void drawLine(float x0, float y0, float x1, float y1);

	void drawRect(iRect rect, float radius = 0.0f);
	void drawRect(float x, float y, float width, float height, float radius = 0.0f);

	void fillRect(iRect rect, float radius = 0.0f);
	void fillRect(float x, float y, float width, float height, float radius = 0.0f);

	Texture* getTexture();


public:


};
