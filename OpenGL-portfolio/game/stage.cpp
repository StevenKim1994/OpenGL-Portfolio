#pragma once
#include "stage.h"
#include "stageTileInfo.h"
#include "Player.h"

uint8 tileAttr[MapTileNumX * MapTileNumY] = {
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,1,5,5,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
};


iPoint offMt;

Player* hero;
int gravity;
bool onLadder = false;


//extern MapTile* mt;
MapTile* mt;

void loadStage()
{
	mt = (MapTile*)malloc(sizeof(MapTile) * MapTileNumX * MapTileNumY);
	int i, num = MapTileNumX * MapTileNumY;

	for (i = 0; i < num; i++)
	{
		MapTile* t = &mt[i];
		t->attr = tileAttr[i];
	}

	offMt = iPointZero;

	hero = new Player();
	hero->setPosition(iPointMake(300, 1528));
	hero->setSize(iSizeMake(MapCharWidth, MapCharHeight));
	hero->setSpeed(MapCharSpeed);
	

}

void freeStage()
{
	free(mt);
	delete hero;
}

void drawStage(float dt)
{

	//---------------------------MapSettings-------------------------------------//
	gravity = powGravity;
	int i, num = MapTileNumX * MapTileNumY;
	for (i = 0; i < num; i++)
	{
		MapTile* t = &mt[i];
		switch (t->attr) {
		case canMove: setRGBA(tile_color_canMove); break;
		case ladder: setRGBA(tile_color_ladder); break;
		//case endofTile: setRGBA(tile_color_end); break;
		case canNotMove: setRGBA(tile_color_canNotMove); break;
		}
		float x = offMt.x + MapTileWidth * (i % MapTileNumX);
		float y = offMt.y + MapTileHeight * (i / MapTileNumX);
		fillRect(x, y, MapTileWidth, MapTileHeight);
		setRGBA(0, 0, 0, 1);
		drawRect(x + 2, y + 2, MapTileWidth - 4, MapTileHeight - 4);
	}

	setRGBA(1, 1, 1, 1);
	iPoint p = hero->getPosition() + offMt;
	iPoint movement = iPointMake(0, 1) * gravity * dt;

	//---------------------------MapSettings-------------------------------------//





	//-----------------------------------KeyInput--------------------------------//
	uint32 keyStat = getKeyStat();
	iPoint v = iPointZero;
	if (keyStat & keyboard_left) v.x = -1;
	else if (keyStat & keyboard_right) v.x = 1;
	if (keyStat & keyboard_up) v.y = -1;
	else if (keyStat & keyboard_down) v.y = 1;

	Behave be = (v == iPointZero ? Behave_idle : Behave_move);
	int dir = hero->direction;
	if (v.x < 0) dir = 0;
	else if (v.x > 0) dir = 1;

	uint32 keyDown = getKeyDown();

	if (keyStat & keyboard_num1)
		be = Behave_meleeAttack;

	hero->setBehave(be, dir);

	//-----------------------------------KeyInput--------------------------------//


	
	
	//-------------------------------------Camera--------------------------------//
	iPoint vp;
	if (v != iPointZero)
	{
		v /= iPointLength(v);
		iPoint mp = v * (hero->getSpeed() * dt);
		hero->move(mp + movement);

		vp = offMt + hero->getPosition();
		if (vp.x < devSize.width * 0.333333f)
		{
			// 왼쪽으로 넘어갔을 경우
			offMt.x += (devSize.width * 0.333333f - vp.x);
			if (offMt.x > 0)
				offMt.x = 0;
		}
		else if (vp.x > devSize.width * 0.666667f)
		{
			// 오른쪽으로 넘어갔을 경우
			offMt.x += (devSize.width * 0.666667f - vp.x);
			if (offMt.x < devSize.width - MapTileWidth * MapTileNumX)
				offMt.x = devSize.width - MapTileWidth * MapTileNumX;
		}
		if (vp.y < devSize.height * 0.333333f)
		{
			// 위로 넘어갔을 경우
			offMt.y += (devSize.height * 0.333333f - vp.y);
			if (offMt.y > 0)
				offMt.y = 0;
		}
		else if (vp.y > devSize.height * 0.666667f)
		{
			// 아래로 넘어갔을 경우
			offMt.y += (devSize.height * 0.666667f - vp.y);
			if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
				offMt.y = devSize.height - MapTileHeight * MapTileNumY;
		}
	}
	else// if(v == iPointZero)
	{
		hero->move(movement);

		vp = offMt + hero->getPosition();

		if (vp.x != devSize.width / 2)
		{
			if (vp.x < devSize.width / 2)
			{
				offMt.x += natureSpeed * dt;//
				vp.x = offMt.x + hero->getPosition().x;
				if (vp.x > devSize.width / 2)
					offMt.x = devSize.width / 2 - hero->getPosition().x;
			}
			else
			{
				offMt.x -= natureSpeed * dt;//
				vp.x = offMt.x + hero->getPosition().x;
				if (vp.x < devSize.width / 2)
					offMt.x = devSize.width / 2 - hero->getPosition().x;
			}
			if (offMt.x > 0)
				offMt.x = 0;
			else if (offMt.x < devSize.width - MapTileWidth * MapTileNumX)
				offMt.x = devSize.width - MapTileWidth * MapTileNumX;
		}
		if (vp.y != devSize.height / 2)
		{
			if (vp.y < devSize.height / 2)
			{
				offMt.y += natureSpeed * dt;//
				vp.y = offMt.y + hero->getPosition().y;
				if (vp.y > devSize.height / 2)
					offMt.y = devSize.height / 2 - hero->getPosition().y;
			}
			else
			{
				offMt.y -= natureSpeed * dt;//
				vp.y = offMt.y + hero->getPosition().y;
				if (vp.y < devSize.height / 2)
					offMt.y = devSize.height / 2 - hero->getPosition().y;
			}
			if (offMt.y > 0)
				offMt.y = 0;
			else if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
				offMt.y = devSize.height - MapTileHeight * MapTileNumY;
		}
		

		
	}

	hero->paint(dt, p);
	

	//-------------------------------------Camera-------------------------------//
}



void keyStage(iKeyState stat, iPoint point)
{
}

void createPopPlayerUI()
{
}

void freePopPlayerUI()
{
}

void drawPopPlayerUI(float dt)
{
}

bool keyPopPlayerUI(iKeyState stat, iPoint point)
{
	return false;
}

void showPopPlayerUI(bool show)
{
}

