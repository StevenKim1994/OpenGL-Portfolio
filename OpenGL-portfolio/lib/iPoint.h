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

#define iPointZero iPointMake(0,0)

iPoint iPointMake(float x, float y);
iPoint iPointVector(iPoint p);
float iPointLength(iPoint p);
iPoint iPointRotate(const iPoint& p, const iPoint& t, float degree);

float iPointDistance(const iPoint& p0, const iPoint& p1);
float iPointAngle(const iPoint& v1, const iPoint& v2, const iPoint& v3);