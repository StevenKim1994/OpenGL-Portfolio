#pragma once

struct iColor4f
{
	float r, g, b, a;
};

struct iColor4b
{
	unsigned char r, g, b, a;
};

#define iColor4fWhite iColor4fMake(1,1,1,1);
#define iColorfBlack iColor4fMake(0,0,0,1);

#define iColor4bWhite iColor4bMake(255,255,255,255);
#define iColor4bBlack iColor4bMake(0,0,0,255);

iColor4f iColor4fMake(float r, float g, float b, float a);
iColor4b iColor4bMake(unsigned char r, unsigned char g, unsigned char b, unsigned char a);