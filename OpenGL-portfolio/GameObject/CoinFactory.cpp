#include "CoinFactory.h"

Object** _coins;
Object** coins;
#define _coinNum 10
int coinNum = 0;

void loadCoin()
{
	_coins = (Object**)malloc(sizeof(Object*) * _coinNum);
	for (int i = 0; i < _coinNum; i++)
		_coins[i] = new Coin();
	coins = (Object**)malloc(sizeof(Object*) * _coinNum);
	coinNum = 0;
}

void freeCoin()
{
	for (int i = 0; i < _coinNum; i++)
		delete _coins[i];
	free(_coins);
	free(coins);
}

extern Player* hero;
void drawCoin(float dt, iPoint off, MapTile* maptile)
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
			audioPlay(7);
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

