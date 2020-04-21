#pragma once

struct iSize
{
	float width, height;

	bool operator == (const iSize& s);
	bool operator != (const iSize& s);

	iSize operator + (const iSize& s);
	iSize& operator += (const iSize& s);

	iSize operator - (const iSize& s);
	iSize& operator -=(const iSize& s);

	iSize operator * (const float f);
	iSize& operator *= (const float f);
	iSize& operator *= (const iSize& s);

	iSize& operator /= (const iSize& s);
	iSize operator / (const float f);
	iSize& operator /= (const float f);

};
#define iSizeZero iSizeMake(0,0)

iSize iSizeMake(float width, float height);
// 넓이 구하는거 추가하기
