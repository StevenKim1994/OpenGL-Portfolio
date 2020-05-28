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
			iImage* img = new iImage();
			ObjInfo* oi = &_oi[i];
			for (int j = 0; j < oi->num; j++)
			{
				Texture* tex = createImage(oi->path, j);
				tex->width *= oi->sizeRate;
				tex->height *= oi->sizeRate;
				tex->potWidth *= oi->sizeRate;
				tex->potHeight *= oi->sizeRate;
				img->addObject(tex);
				freeImage(tex);
			}

			switch (i)
			{
			case 0:
				img->_repeatNum = 0;
				break;

			default:
				img->_repeatNum = 1;
				break;
			}
			img->_aniDt = 0.1f;
			img -> position = oi->p;
			imgCoin[i] = img;
		}
	}

	imgs = (iImage**)malloc(sizeof(iImage*) * 1);
	for (int i = 0; i < 1; i++)
		imgs[i] = imgCoin[i]->copy();

	img = imgs[0];
	img->startAnimation();

	alive = false;
}

Coin::~Coin()
{
	if (imgCoin)
	{
		for (int i = 0; i < 1; i++)
			delete imgCoin[i];
		free(imgCoin);
		imgCoin = NULL;

	}

	for (int i = 0; i < i; i++)
		delete imgs[i];
	
	free(imgs);
}

void Coin::paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY)
{
	if (stat == CoinStat_wait)
	{
		iPoint off = iPointMake(0, -50*_sin(delta / coin_wait_delta));

		img->paint(dt, position + offset + off);

		delta += dt;
		if (delta > coin_wait_delta)
			delta = coin_wait_delta;
	}
	else if (stat == CoinStat_move)
	{
		float r = delta / coin_move_delta;
		position = sp * (1.0f - r) + tp * r;

		float s;
		if (r < 0.5f)	s = 1.0f;
		else			s = linear((r - 0.5) / 0.5, 1.0f, 0.0f);
		float d = 0.0f;

		Texture* tex = (Texture*)img->arrayTex->objectAtIndex(0);
		drawImage(tex, position.x, position.y, 0, 0, tex->width, tex->height, VCENTER | HCENTER, s, s, 2, d, REVERSE_NONE);

		delta += dt;
		if (delta > coin_move_delta)
		{
			delta = 0.0f;
			stat = CoinStat_disappear;
		}
	}
	else if (stat == CoinStat_disappear)
	{
		position = tp;
		float r = delta / coin_disappear_delta;
		float s = linear(r, 1.0f, 5.0f);
		setRGBA(1, 1, 1, linear(r, 1.0f, 0.0f));

		Texture* tex = (Texture*)img->arrayTex->objectAtIndex(0);
		drawImage(tex, position.x, position.y, 0, 0, tex->width, tex->height, VCENTER | HCENTER, s, s, 2, 0.0f, REVERSE_NONE);

		setRGBA(1, 1, 1, 1);

		delta += dt;
		if (delta > coin_disappear_delta)
		{
			delta = 0.0f;
			alive = false;
		}
	}
}

void Coin::set(iPoint p, int price)
{
	alive = true;
	stat = CoinStat_wait;
	position = p;
	//sp, tp;
	delta = 0.0f;
	this->price = price;
}

bool Coin::touchRect(iPoint p)
{
	return containPoint(p, iRectMake(position.x - 16, position.y - 16, 32, 32));
}

Object** _coins;
Object** coins;
#define _coinNum 10
int coinNum = 0;

void loadCoin()
{
	_coins = (Object**)malloc(sizeof(Object) * _coinNum);
	for (int i = 0; i < _coinNum; i++)
		_coins[i] = new Coin();
	coins = (Object**)malloc(sizeof(Object) * _coinNum);
	coinNum = 0;
}

void freeCoin()
{
	free(_coins);
	free(coins);
}

extern Player* hero;
void drawCoin(float dt, iPoint off , MapTile* maptile)
{
	for (int i = 0; i < coinNum; i++)
	{
		Coin* c = (Coin*)coins[i];
		if (c->alive == false)
		{
			coinNum--;
			coins[i] = coins[coinNum];
			i--;
			continue;
		}
		c->paint(dt, off, maptile, stageMapTileNumX, stageMapTileNumY);
	}

	checkCoin(hero->position, off);
}

void checkCoin(iPoint p, iPoint off)
{
	for (int i = 0; i < coinNum; i++)
	{
		Coin* c = (Coin*)coins[i];
		if (c->touchRect(p))
		{
			c->stat = CoinStat_move;
			c->delta = 0.0f;
			c->sp = c->position + off;
			c->tp = iPointMake(devSize.width, devSize.height);
			printf("get Coin! %d\n", c->price);
			
		}
	}
}

void addCoin(iPoint p, int price)
{
	for (int i = 0; i < _coinNum; i++)
	{
		Coin* c = (Coin*)_coins[i];
		if (c->alive == false)
		{
			c->set(p, price);
			coins[coinNum] = c;
			coinNum++;
			return;
		}
	}
}

