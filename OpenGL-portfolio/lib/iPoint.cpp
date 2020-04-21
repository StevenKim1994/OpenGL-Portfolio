#include "iPoint.h"

#include "iStd.h"
#include <math.h>

bool iPoint::operator==(const iPoint& p)
{
	return (x == p.x && y == p.y);
}

bool iPoint::operator!=(const iPoint& p)
{
	return (x != p.x || y != p.y);
}

iPoint iPoint::operator+(const iPoint& p)
{
	iPoint r;
	r.x = x + p.x;
	r.y = y + p.y;
	return r;
}

iPoint& iPoint::operator+=(const iPoint& p)
{
	x += p.x;
	y += p.y;
	return *this;
}

iPoint iPoint::operator-(const iPoint& p)
{
	iPoint r;
	r.x = x - p.x;
	r.y = y - p.y;
	return r;
}

iPoint& iPoint::operator-=(const iPoint& p)
{
	x -= p.x;
	y -= p.y;
	return *this;
}

iPoint iPoint::operator*(const float f)
{
	iPoint r;
	r.x = x * f;
	r.y = y * f;
	return r;
}

iPoint& iPoint::operator*=(const float f)
{
	x *= f;
	y *= f;
	return *this;
}

iPoint& iPoint::operator/=(const iPoint& p)
{
	x /= p.x;
	y /= p.y;
	return *this;
}

iPoint iPoint::operator/(const float f)
{
	iPoint r;
	r.x = x / f;
	r.y = y / f;
	return r;
}

iPoint& iPoint::operator/=(const float f)
{
	x /= f;
	y /= f;
	return *this;
}

iPoint iPointMake(float x, float y)
{
	iPoint r;
	r.x = x;
	r.y = y;
	return r;
}

iPoint iPointVector(iPoint p)
{
	return p / sqrtf(p.x * p.x + p.y * p.y);
}

float iPointLength(iPoint p)
{
	return sqrtf(p.x * p.x + p.y * p.y);
}

iPoint iPointRotate(const iPoint& p, const iPoint& t, float degree)
{
	while (degree < 0)	degree += 360;
	while (degree > 360) degree -= 360;
	float sinr = _sin(degree);
	float cosr = _cos(degree);

	iPoint r = iPointMake(p.x - t.x, t.y - p.y);
	iPoint _p;
	_p.x = r.x * cosr - r.y * sinr;
	_p.y = r.x * sinr + r.y * cosr;

	_p.x = t.x + _p.x;
	_p.y = t.y - _p.y;
	return _p;
}
