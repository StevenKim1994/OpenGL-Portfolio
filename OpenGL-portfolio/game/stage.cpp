#pragma once
#include "stage.h"
#include "stageTileInfo.h"
#include "Player.h"


uint8 tileAttr[MapTileNumX * MapTileNumY] = {

	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 5,
	5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 5,
	5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5,
	5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 5,
	5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5,
	5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5,
	5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5,
	5, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 5,
	5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};



#define ON_HITBOX 0

Player* hero;
MapTile* maptile;
iPoint offMt;

MapHero* mh;


void loadStage()
{
	int i, num = MapTileNumX * MapTileNumY;
	maptile = (MapTile*)malloc(sizeof(MapTile) * num);
	for (i = 0; i < num; i++)
	{
		MapTile* t = &maptile[i];
		t->attr = tileAttr[i];
		//t->imgIndex;
	}

	offMt = iPointZero;
	hero = new Player();

	hero->setSize(iSizeMake(PlayerWidth, PlayerHeight));

	hero->setSpeed(MapCharSpeed);
	hero->setPosition(iPointMake(200,300));

}

void freeStage()
{
	free(maptile);
	//free(mh);
	delete hero;
}

void drawStage(float dt)
{
	int i, num = MapTileNumX * MapTileNumY;
	for (i = 0; i < num; i++)
	{
		MapTile* t = &maptile[i];
		switch (t->attr) {
		case 0: setRGBA(tile_color_canMove); break;
		case 1: setRGBA(tile_color_canNotMove); break;
		case 2: setRGBA(tile_color_end); break;
		}
		float x = offMt.x + MapTileWidth * (i % MapTileNumX);
		float y = offMt.y + MapTileHeight * (i / MapTileNumX);
		fillRect(x, y, MapTileWidth, MapTileHeight);
		setRGBA(0, 0, 0, 1);
		drawRect(x + 2, y + 2, MapTileWidth - 4, MapTileHeight - 4);
	}

	//setRGBA(hero_color);
	setRGBA(1, 1, 1, 1);
	
	


	iPoint movement = iPointMake(0, 1) * 100 * dt; // powGravity* dt;
	//mh->applyJump(movement, dt);

	if (getKeyDown() & keyboard_space)
	{
		//if (getKeyStat() & keyboard_down)
		//	mh->position.y += 1;
		//else

		//mh->jump();
	}
	uint32 keyStat = 0;
	uint32 keyDown = 0;
	if (hero->behave != Behave_meleeAttack)
	{
		 keyStat = getKeyStat();
		 keyDown = getKeyDown();
	}
	iPoint v = iPointZero;
	if (keyStat & keyboard_left) v.x = -1;
	else if (keyStat & keyboard_right) v.x = 1;
	if (keyStat & keyboard_up) v.y = -1;
	else if (keyStat & keyboard_down) v.y = 1;

	
	Behave be;
	if (keyDown & keyboard_num1)
		be = Behave_meleeAttack;

	else if (keyDown & keyboard_space)
		be = Behave_jumpAndFall;
	
	else
		be = (v == iPointZero ? Behave_idle : Behave_move);
	int dir = hero->direction;
	if (v.x < 0) dir = 0;
	else if (v.x > 0) dir = 1;

	
	if( hero->behave!=Behave_meleeAttack )
		hero->setBehave(be, dir);



	if (v != iPointZero)
	{
		v /= iPointLength(v);
		iPoint mp = v * (hero->getSpeed() * dt);
		//mh->move(mp + movement);
		hero->move(mp + movement,maptile);

		iPoint vp = offMt + hero->getPosition();
		hero->paint(dt, vp);
		
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
#if DEBUG
		//hitbox
		drawRect((hero->getPosition().x - hero->getSize().width / 2) + offMt.x,
			(hero->getPosition().y - hero->getSize().height) + offMt.y, hero->getSize().width, hero->getSize().height);
#endif
	}
	else// if(v == iPointZero)
	{
		//mh->move(movement);
		hero->move(movement, maptile);
		iPoint vp = offMt + hero->getPosition();// mh->position;
		hero->paint(dt, vp);
		
		if (vp.x != devSize.width / 2)
		{
			if (vp.x < devSize.width / 2)
			{
				offMt.x += natureSpeed * dt;//
				vp.x = offMt.x + hero->getPosition().x;//mh->position.x;
				if (vp.x > devSize.width / 2)
					offMt.x = devSize.width / 2 - hero->getPosition().x;//mh->position.x;
			}
			else
			{
				offMt.x -= natureSpeed * dt;//
				vp.x = offMt.x + hero->getPosition().x;//mh->position.x;
				if (vp.x < devSize.width / 2)
					offMt.x = devSize.width / 2 - hero->getPosition().x;//mh->position.x;
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
				vp.y = offMt.y + hero->getPosition().y;//mh->position.y;
				if (vp.y > devSize.height / 2)
					offMt.y = devSize.height / 2 - hero->getPosition().y; // mh->position.y;
			}
			else
			{
				offMt.y -= natureSpeed * dt;//
				vp.y = offMt.y + hero->getPosition().y;//mh->position.y;
				if (vp.y < devSize.height / 2)
					offMt.y = devSize.height / 2 - hero->getPosition().y;//mh->position.y;
			}
			if (offMt.y > 0)
				offMt.y = 0;
			else if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
				offMt.y = devSize.height - MapTileHeight * MapTileNumY;
		}

		//hitbox
#if ON_HITBOX
		drawRect((hero->getPosition().x - hero->getSize().width / 2)+ offMt.x,
				(hero->getPosition().y - hero->getSize().height)+ offMt.y, hero->getSize().width, hero->getSize().height);

#endif
	}

	// scroll type
	// 1. 항상 주인공 센터
	// 2. 액정의 범위 벗어나면 스크롤

	// 카메라
	// 실시간
	// 따라가는

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





void keyJump(iKeyState stat, iPoint point)
{
}

