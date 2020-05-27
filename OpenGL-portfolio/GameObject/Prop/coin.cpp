#pragma once

#include "coin.h"

static iImage** imgCoin = NULL;

Coin::Coin()
{
	if (imgCoin == NULL)
	{
		ObjInfo _oi[1] =
		{
			{"assets/stage/props/coin/tile%03d.png", 4, 2.0f,iPointZero } ,
		};

		iGraphics* g = iGraphics::instance();
		iSize size;

		imgCoin = (iImage**)malloc(sizeof(iImage*) * 1);

		for (int i = 0; i < 1; i++)
		{

		}
	}
}

Coin::~Coin()
{
}
