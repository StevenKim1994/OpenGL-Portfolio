#pragma once

#include "iType.h"

typedef void (*IMAGE_METHOD)(void* cb);

class iImage
{
public:
	iImage();
	virtual ~iImage();

	static void freeTex(void* data);

	void addObject(Texture* tex);
	void setTexAtIndex(int index);
	void replaceAtIndex(int index, Texture* tex);

	void paint(float dt, iPoint off);
	void startAnimation(IMAGE_METHOD m = 0, void* cb = 0);

	iRect touchRect(iPoint p = iPointMake(0, 0));
	iImage* copy();

public:
	iArray* arrayTex;
	Texture* tex;
	iPoint position;

	bool selected;
	float selectedDt, _selectedDt;
	float selectedScale;

	bool animation;
	float aniDt, _aniDt;
	int frame;
	bool lastFrame;
	int repeatNum, _repeatNum;	// 0 : inf
	IMAGE_METHOD method;
	void* cb;
	int anc;
	float degree;
	float scale;

	int8 leftRight;// 0 : original, 1: w 반전 2: h 반전
};

#define default_selectedDt 0.1f
#define default_selectedScale -0.2f

