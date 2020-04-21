#include "iColor.h"

iColor4f iColor4fMake(float r, float g, float b, float a)
{
	iColor4f c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return c;
}

iColor4f iColor4bMake(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	iColor4f c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return c;
}
