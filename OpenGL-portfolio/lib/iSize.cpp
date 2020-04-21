#include "iSize.h"

iSize iSizeMake(float width, float height)
{
	iSize r;
	r.width = width;
	r.height = height;
	return r;
}

bool iSize::operator==(const iSize& s)
{
	return (width == s.width && height == s.height);
}

bool iSize::operator!=(const iSize& s)
{
	return (width != s.width && height != s.height);
}

iSize iSize::operator+(const iSize& s)
{
	iSize r;
	r.width = width + s.width;
	r.height = height + s.height;

	return r;
}

iSize& iSize::operator+=(const iSize& s)
{
	width += s.width;
	height += s.height;
	return *this;

}

iSize iSize::operator-(const iSize& s)
{
	iSize r;
	r.width = width - s.width;
	r.height = height - s.height;
	return r;
}

iSize& iSize::operator-=(const iSize& s)
{
	width -= s.width;
	height -= s.height;
	return *this;
}

iSize iSize::operator*(const float f)
{
	iSize r;
	r.width = width * f;
	r.height = height * f;
	return r;
}

iSize& iSize::operator*=(const float f)
{
	width *= f;
	height *= f;

	return *this;
}

iSize& iSize::operator*=(const iSize& s)
{
	width *= s.width;
	height *= s.height;

	return *this;
}

iSize& iSize::operator/=(const iSize& s)
{
	width /= s.width;
	height /= s.height;
	return *this;
}

iSize iSize::operator/(const float f)
{
	iSize r;
	r.width = width / f;
	r.height = height / f;
	return r;
}

iSize& iSize::operator/=(const float f)
{
	width /= f;
	height /= f;
	return *this;
}
