#include "iSort.h"

#include "stdlib.h"

iSort::iSort()
{
	sd = (iSortData*)malloc(sizeof(iSortData) * _sdNum);
}

iSort::~iSort()
{
	free(sd);
}

void iSort::init()
{
	sdNum = 0;
}

void iSort::add(float y)
{
	iSortData* d = &sd[sdNum];
	d->index = sdNum;
	d->y = y;
	sdNum++;
}

void iSort::update()
{
#if 1// bubble
	int i, j, num = sdNum - 1;
	iSortData tmp;

	for (i = 0; i < num; i++)
	{
		for (j = 1 + i; j < sdNum; j++)
		{
			if (sd[i].y > sd[j].y)
			{
				tmp = sd[i];
				sd[i] = sd[j];
				sd[j] = tmp;
			}
		}
	}
#else// quick

#endif
}

int iSort::get(int i)
{
	return sd[i].index;
}
