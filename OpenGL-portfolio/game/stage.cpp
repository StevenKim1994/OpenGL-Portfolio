#pragma once
#include "stage.h"

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

MapTile* mt;
iPoint offMt;

MapHero* mh;
int gravity;
bool onLadder = false;

void loadStage()
{
	int i, num = MapTileNumX * MapTileNumY;
	mt = (MapTile*)malloc(sizeof(MapTile) * num);
	for (i = 0; i < num; i++)
	{
		MapTile* t = &mt[i];
		t->attr = tileAttr[i];
		//t->imgIndex;
	}

	offMt = iPointZero;

	mh = (MapHero*)malloc(sizeof(MapHero));
	mh->position = iPointMake(300,1528);
	mh->size = iSizeMake(MapCharWidth, MapCharHeight);
	mh->speed = MapCharSpeed;
	mh->jumpment = iPointZero;
	mh->jumpNum = 0;
	mh->_jumpNum = 2;
	mh->idle = new iImage();
	mh->meleeAttack = new iImage();
	

	iGraphics* g = iGraphics::instance();
	iSize size;


	for (i = 0; i < 15; i++) // idle motion
	{
		Texture* tex;
		igImage* ig = g->createIgImage("assets/stage/hero/Knight/hero_idle (%d).png", i + 1);
		size = iSizeMake(g->getIgImageWidth(ig) * 3.0, g->getIgImageHeight(ig) * 3.0);
		g->init(size);

		g->drawImage(ig, 0, 0, 3.0, 3.0, TOP | LEFT);
		
		tex = g->getTexture();
	
		mh->idle->addObject(tex);
		freeImage(tex);
	}

	mh->state = 0; // 기본 idle 상태
	mh->idle->_aniDt = 0.1f;
	mh->idle->repeatNum = 0; // infinity
	mh->idle->animation = true;
	
	for (i = 0; i < 22; i++) // meleeAttack motion
	{
		Texture* tex;
		igImage* ig = g->createIgImage("assets/stage/hero/Knight/hero_melee (%d).png", i + 1);
		size = iSizeMake(g->getIgImageWidth(ig) * 3.0, g->getIgImageHeight(ig) * 3.0);
		g->init(size);

		g->drawImage(ig, 0, 0, 3.0, 3.0, TOP | LEFT);

		tex = g->getTexture();

		mh->meleeAttack->addObject(tex);
		freeImage(tex);

	}

	mh->meleeAttack->repeatNum = 3;
	mh->meleeAttack->_aniDt = 0.1f;
	mh->meleeAttack->animation = true;




}

void freeStage()
{
	free(mt);
	free(mh);
}

void drawStage(float dt)
{
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

#if 0
	setRGBA(hero_color);
	fillRect(mh->position.x + offMt.x - mh->size.width / 2,
		mh->position.y + offMt.y - mh->size.height / 2,
		mh->size.width, mh->size.height);// drawImage(mh->idle->)
#else
	setRGBA(1, 1, 1, 1);
	iPoint p = mh->position + offMt;
	

	
	
	

#endif

	iPoint movement = iPointMake(0, 1) * gravity * dt;

	mh->applyJump(movement, dt);

	mh->meleeAttack->paint(dt, p);

	/*switch (mh->state)
	{
	case 0:
		mh->idle->paint(dt, p);
		break;

	case 1:
		mh->meleeAttack->paint(dt, p);
		break;
	}*/

	
	uint32 keyStat = getKeyStat();
	iPoint v = iPointZero;
	if (keyStat & keyboard_left) v.x = -1;
	else if (keyStat & keyboard_right) v.x = 1;
	if (keyStat & keyboard_up) v.y = -1;
	else if (keyStat & keyboard_down) v.y = 1;
	if (v != iPointZero)
	{
		v /= iPointLength(v);
		iPoint mp = v * (mh->speed * dt);
		mh->move(mp + movement);

		iPoint vp = offMt + mh->position;
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
		mh->move(movement);

		iPoint vp = offMt + mh->position;

		if (vp.x != devSize.width / 2)
		{
			if (vp.x < devSize.width / 2)
			{
				offMt.x += natureSpeed * dt;//
				vp.x = offMt.x + mh->position.x;
				if (vp.x > devSize.width / 2)
					offMt.x = devSize.width / 2 - mh->position.x;
			}
			else
			{
				offMt.x -= natureSpeed * dt;//
				vp.x = offMt.x + mh->position.x;
				if (vp.x < devSize.width / 2)
					offMt.x = devSize.width / 2 - mh->position.x;
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
				vp.y = offMt.y + mh->position.y;
				if (vp.y > devSize.height / 2)
					offMt.y = devSize.height / 2 - mh->position.y;
			}
			else
			{
				offMt.y -= natureSpeed * dt;//
				vp.y = offMt.y + mh->position.y;
				if (vp.y < devSize.height / 2)
					offMt.y = devSize.height / 2 - mh->position.y;
			}
			if (offMt.y > 0)
				offMt.y = 0;
			else if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
				offMt.y = devSize.height - MapTileHeight * MapTileNumY;
		}
	}

	// scroll type
	// 1. 항상 주인공 센터
	// 2. 액정의 범위 벗어나면 스크롤

	// 카메라
	// 실시간
	// 따라가는
}

void MapHero::applyJump(iPoint& movement, float dt)
{
	if (jumpment == iPointZero)
		return;

	iPoint mp = jumpment * dt;
	movement += mp;
	jumpment -= mp;
}


void MapHero::idleMotion(iPoint v)
{
	
}

void MapHero::meleeAttackMotion(int direction)
{
}




void MapHero::jump()
{
	if (jumpNum == _jumpNum)
		return;

	jumpNum++;
	jumpment = iPointMake(0, -1) * powJump;
}
void MapHero::move(iPoint movement)
{
	iPoint mp = movement;
	if (mp.x < 0)
	{
		// left
		int tlx = position.x - size.width / 2; tlx /= MapTileWidth;
		int tly = position.y - size.height / 2; tly /= MapTileHeight;
		int bly = position.y + size.height / 2; bly /= MapTileHeight;
		int min = 0;
		for (int x = tlx - 1; x > -1; x--)
		{
			bool col = false;
			for (int y = tly; y < bly + 1; y++)
			{
				if (mt[MapTileNumX * y + x].attr == canNotMove || (mt[MapTileNumX*y+x].attr == endofTile))
				{
					col = true;
					min = MapTileWidth * (x + 1);
					break;
				}
			}
			if (col)
				break;
		}
		//printf("min = %d, curr = %f\n", min, position.x);
		position.x += mp.x;
		if (position.x < min + size.width / 2)
			position.x = min + size.width / 2;
	}
	else if (mp.x > 0)
	{
		// right
		int TRX = position.x + size.width / 2; TRX /= MapTileWidth;
		int TRY = position.y - size.height / 2; TRY /= MapTileHeight;
		int BRY = position.y + size.height / 2; BRY /= MapTileHeight;
		int min = MapTileWidth * MapTileNumX;
		for (int x = TRX + 1; x < MapTileNumX; x++)
		{
			bool col = false;
			for (int y = TRY; y < BRY + 1; y++)
			{
				if (mt[MapTileNumX * y + x].attr == canNotMove || (mt[MapTileNumX*y+x].attr == endofTile))
				{
					col = true;
					min = MapTileWidth * x - 1;
					break;
				}
			}
			if (col)
				break;
		}
		//printf("min = %d, curr = %f\n", min, position.x);
		position.x += mp.x;
		if (position.x > min - size.width / 2)
			position.x = min - size.width / 2;
	}


	if (mp.y < 0)
	{
		// up
		int TLY = position.y - size.height / 2; TLY /= MapTileHeight;
		int TLX = position.x - size.width / 2; TLX /= MapTileWidth;
		int TRX = position.x + size.width / 2; TRX /= MapTileWidth;
		int min = 0;
		for (int y = TLY - 1; y > -1; y--)
		{
			bool col = false;
			for (int x = TLX; x < TRX + 1; x++)
			{
				if (mt[MapTileNumX * y + x].attr == canNotMove || (mt[MapTileNumX * y + x].attr == endofTile))
				{
					col = true;
					min = MapTileHeight * (y + 1);
					break;
				}

				if (mt[MapTileNumX * y + x].attr == ladder)
				{
					onLadder = true;
					mh->speed += 200;
				}

				else
				{
					onLadder = false;
					mh->speed = natureSpeed;
				}

			}
			if (col)
				break;
		}
		//printf("min = %d, curr = %f\n", min, position.x);
		position.y += mp.y;
		if (position.y < min + size.height / 2)
			position.y = min + size.height / 2;

		
	}
	else if (mp.y > 0)
	{
		// down
		int TLY = position.y + size.height / 2; TLY /= MapTileHeight;
		int TLX = position.x - size.width / 2; TLX /= MapTileWidth;
		int TRX = position.x + size.width / 2; TRX /= MapTileWidth;
		int min = MapTileHeight * MapTileNumY;
		for (int y = TLY + 1; y < MapTileNumY; y++)
		{
			bool col = false;
			for (int x = TLX; x < TRX + 1; x++)
			{
				if (mt[MapTileNumX * y + x].attr == canNotMove||(mt[MapTileNumX*y + x].attr == endofTile))
				{
					col = true;
					min = MapTileHeight * y - 1;
					break;
				}
			}
			if (col)
				break;
		}
		//printf("min = %d, curr = %f\n", min, position.x);
		position.y += mp.y;
		if (position.y > min - size.height / 2)
			position.y = min - size.height / 2;

		if (position.y == min - size.height / 2)
			jumpNum = 0;
	}
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

