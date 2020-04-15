#include "iRect.h"

iRect iRectMake(float x, float y, float width, float height)
{
	iRect rt;
	rt.origin.x = x;
	rt.origin.y = y;
	rt.size.width = width;
	rt.size.height = height;

	return rt;
}
