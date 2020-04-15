#pragma once

struct iPoint
{
	float x, y;

	bool operator == (const iPoint& p);
	bool operator != (const iPoint& p);

	iPoint operator + (const iPoint& p);
	iPoint& operator += (const iPoint& p);

	iPoint operator - (const iPoint& p);
	iPoint& operator -= (const iPoint& p);

	iPoint operator * (const float f);
	iPoint& operator *= (const float f);

	iPoint& operator /= (const iPoint& p);
	iPoint operator / (const float f);
	iPoint& operator /= (const float f);
	
};

iPoint iPointMake(float x, float y);
iPoint iPointVector(iPoint p);
float iPointLength(iPoint p);
iPoint iPointRotate(const iPoint& p, const iPoint& t, float degree);