#pragma once

#include "iPoint.h"
#include "iSize.h"

struct iRect
{
	iPoint origin;
	iSize size;
	
};

iRect iRectMake(float x, float y, float width, float height);