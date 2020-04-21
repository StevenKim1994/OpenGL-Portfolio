#pragma once

#include "iType.h"

struct Texture;

typedef Texture* (*method_istrtex)(const char* str);

class iStrTex
{
public:
	iStrTex(method_istrtex m = NULL);
	virtual ~iStrTex();

public:
	void setString(const char* szFormat, ...);

	void paint(int x, int y, int anc);
	void paint(int x, int y, int anc, const char* szFormat, ...);

	void paint(int x, int y, float rateX, float rateY, int anc);
	void paint(int x, int y, float rateX, float rateY, int anc, const char* szFormat, ...);

public:
	method_istrtex method;

	char* str;
	int strLength;

	Texture* tex;
};


