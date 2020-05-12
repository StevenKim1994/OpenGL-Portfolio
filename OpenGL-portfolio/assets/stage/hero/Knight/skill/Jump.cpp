#include "Jump.h"

#include "Loading.h"

uint8 tileAttr[MapTileNumX*MapTileNumY] ={
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
	2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,0,0,1,
	1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,1,
	1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,1,0,0,1,
	1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,
	1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,
	1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,
	1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,
	1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

};

MapTile* mt;
iPoint offMt;

MapHero* mh;

void loadJump()
{
	int i;
	int num = MapTileNumX * MapTileNumY;
	mt = (MapTile*)malloc(sizeof(MapTile) * num);

	for (i = 0; i < num; i++)
	{
		MapTile* t = &mt[i];
		t->attr = tileAttr[i];
		//t->ImgIndex;
	}

	offMt = iPointZero;

	mh = (MapHero*)malloc(sizeof(MapHero));
	mh->positon = iPointMake(MapTileWidth*4 + MapTileWidth / 2, MapTileHeight* 1+ MapTileHeight / 2);
	mh->size = iSizeMake(MapCharWidth, MapCharHeight);
	mh->speed = Mapcharspeed;
	mh->jumpment = iPointZero;
	mh->jumpNum = 0;
	mh->_jumpNum = 1;
}

void freeJump()
{
	free(mt);
	free(mh);
}


void drawJump(float dt)
{
	int i;
	int num = MapTileNumX * MapTileNumY;

	for (i = 0; i < num; i++)
	{
		MapTile* t = &mt[i];
		switch (t->attr)
		{
		case 0:	setRGBA(tile_Color_canMove); break;
		case 1: setRGBA(tile_Color_NotMove); break;
		case 2: setRGBA(tile_Color_end); 	 break;
		}
		float x = offMt.x + MapTileWidth * (i % MapTileNumX);
		float y = offMt.y + MapTileHeight * (i / MapTileNumX);

		fillRect(x,	 y,	 MapTileWidth, MapTileHeight);
		setRGBA(0, 0, 0, 1);
		drawRect(x, y, MapTileWidth, MapTileHeight);
	}
	setRGBA(1, 1, 1, 1);

	setRGBA(Hero_color);
	fillRect(mh->positon.x + offMt.x - mh->size.width / 2,
			 mh->positon.y + offMt.y - mh->size.height / 2,
			 mh->size.width, mh->size.height);
	setRGBA(1, 1, 1, 1);

	iPoint movement = iPointMake(0, 1) * powergravity * dt;

	mh->applyJump(movement, dt);

	if (getKeyDown() & keyboard_space)
	{
		if (getKeyStat() & keyboard_down)
			mh->positon.y += 1;
		mh->jump();
	}


	uint32 keystat = getKeyStat();
	iPoint v = iPointZero;
	if		(keystat & keyboard_left)   v.x = -1;
	else if (keystat & keyboard_right)  v.x = 1;
	if		(keystat & keyboard_up)		v.y = -1;
	else if (keystat & keyboard_down)   v.y = 1;
	if (v != iPointZero)
	{
		v /= iPointLength(v);
		iPoint mp = v * (mh->speed * dt);
		mh->move(mp+movement);

	    //mh->move(mp + movement);

		iPoint vp = offMt + mh->positon;
	#if 0 //실시간 이면서 화면 센터
		if (vp.x != devSize.width / 2)
		{
			offMt.x = devSize.width / 2 - mh->positon.x; //vp.x = devSize.width / 2;
			if (offMt.x > 0)
				offMt.x = 0;
			else if (offMt.x < devSize.width - MapTileWidth * MapTileNumX)
				offMt.x = devSize.width - MapTileWidth * MapTileNumX;
		}
		if (vp.y != devSize.height / 2)
		{
			offMt.y = devSize.height / 2 - mh->positon.y; //vp.x = devSize.width / 2;
			if (offMt.y > 0)
				offMt.y = 0;
			else if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
				offMt.y = devSize.height - MapTileHeight * MapTileNumY;
		}
		printf("offMT.X = %f, offMT.Y = %f\n", offMt.x, offMt.y);
	
	#else
		// 실시간 + 1/3 벗어난 경우
		if (vp.x < devSize.width * 0.2f)
		{
			offMt.x += devSize.width * 0.2f - vp.x; //vp.x = devSize.width / 2;
			if (offMt.x > 0)
				offMt.x = 0;
		}
		else if (vp.x > devSize.width * 0.8f)
		{
			offMt.x += devSize.width * 0.8f - vp.x; //vp.x = devSize.width / 2;
			if (offMt.x < devSize.width - MapTileWidth * MapTileNumX)
				offMt.x = devSize.width - MapTileWidth * MapTileNumX;
		}
		if (vp.y < devSize.height * 0.2f)
		{
			offMt.y += devSize.height * 0.2f - vp.y; //vp.x = devSize.width / 2;
			if (offMt.y > 0)
				offMt.y = 0;
	
		}
		else if (vp.y > devSize.height * 0.8f)
		{
			offMt.y += devSize.height * 0.8f - vp.y; //vp.x = devSize.width / 2;
			if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
				offMt.y = devSize.height - MapTileHeight * MapTileNumY;
	
		}
		//움직일떄
#endif
	}
	else
	{
		mh->move(movement);

		iPoint vp = offMt + mh->positon;
		if (vp.x != devSize.width / 2)
		{
			if (vp.x < devSize.width / 2)
			{
				offMt.x += Naturespeed * dt;
				vp.x = offMt.x + mh->positon.x;
				if(vp.x>devSize.width/2)
					offMt.x = devSize.width / 2 - mh->positon.x;
			}
			else
			{
				offMt.x -= Naturespeed * dt;
				vp.x = offMt.x + mh->positon.x;
				if (vp.x < devSize.width / 2)
					offMt.x = devSize.width / 2 - mh->positon.x;
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
				offMt.y += Naturespeed * dt;
				vp.y = offMt.y + mh->positon.y;
				if (vp.y > devSize.height / 2)
					offMt.y = devSize.height / 2 - mh->positon.y;
			}
			else
			{
				offMt.y -= Naturespeed * dt;
				vp.y = offMt.y + mh->positon.y;
				if (vp.y < devSize.height / 2)
					offMt.y = devSize.height / 2 - mh->positon.y;
			}

			if (offMt.y > 0)
				offMt.y = 0;
			else if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
				offMt.y = devSize.height - MapTileHeight * MapTileNumY;
		}

	}
		//움직이지 않을떄



	//scroll type
	// 1. 주인공이 센터
	// 2. 특정한 영역을 가게되면 스크롤, 액정의 범위에 벗어나면 스크롤
	
	//실시간 카메라
	//따라가는 카메라

}

void MapHero::move(iPoint movement)
{
	//mh->positon += movement;

	if (movement.x < 0)
	{
		int tlx = positon.x - size.width  / 2; tlx /= MapTileWidth;
		int tly = positon.y - size.height / 2; tly /= MapTileHeight;
		int bly = positon.y + size.height / 2; bly /= MapTileHeight;
		int min = 0;

		for (int x = tlx - 1; x > -1; x--)
		{
			bool col = false;
			for (int y = tly; y < bly + 1; y++)
			{
				if (mt[MapTileNumX * y + x].attr == 1)
				{
					col = true;
					min = MapTileWidth * (x + 1);
					break;
				}
			}
			if (col)
				break;
		}
		
		positon.x += movement.x;
		if (positon.x < min + size.width / 2)
			positon.x = min + size.width / 2;
		//왼쪽
	}
	else if (movement.x > 0)
	{
		int trX = positon.x + size.width / 2; trX /= MapTileWidth;
		int trY = positon.y - size.height / 2; trY /= MapTileHeight;
		int brY = positon.y + size.height / 2; brY /= MapTileHeight;
		int min = MapTileWidth * MapTileNumX;

		for (int x = trX + 1; x <  MapTileNumX  ; x++)
		{
			bool col = false;
			for (int y = trY; y < brY +1 ; y++)
			{
				if (mt[MapTileNumX * y + x ].attr == 1)
				{
					col = true;
					min = MapTileWidth * x - 1;	
					break;
				}
			}
			if (col)
				break;
		}


		positon.x += movement.x;
			
		if (positon.x > min - size.width / 2)
			positon.x = min - size.width / 2;

		//오른쪽
	}

	if (movement.y < 0)
	{
		int lty = positon.y - size.height / 2; lty /= MapTileHeight;
		int ltx = positon.x - size.width / 2; ltx /= MapTileWidth;
		int rtx = positon.x + size.width / 2; rtx /= MapTileWidth;
		int min = 0;

		for (int y = lty - 1; y > - 1; y--)
		{
			bool col = false;
			for (int x = ltx; x < rtx + 1; x++)
			{
				if (mt[MapTileNumX * y + x].attr == 1)
				{
					col = true;
					min = MapTileHeight * (y + 1);
					break;
				}
			}
			if (col)
				break;
		}

		positon.y += movement.y;
		if (positon.y < min + size.height/ 2)
			positon.y = min + size.height / 2;

		//위로
	}
	else if (movement.y > 0)
	{
		int lby = positon.y + size.height / 2; lby /= MapTileHeight;
		int lbx = positon.x - size.width / 2; lbx /= MapTileWidth;
		int rbx = positon.x + size.width / 2; rbx /= MapTileWidth;
		int min = MapTileHeight * MapTileNumY;

		for (int y = lby + 1; y < MapTileNumY; y++)
		{
			bool col = false;
			for (int x = lbx; x < rbx + 1; x++)
			{
				if (mt[MapTileNumX * y + x].attr == 1)
				{
					col = true;
					min = MapTileHeight * (y) - 1;
					break;
				}
			}
			if (col)
				break;
		}


		positon.y += movement.y;

			if (positon.y > min - size.height / 2)
				positon.y = min - size.height / 2;

			if(positon.y == min - size.height / 2)
			 mh->jumpNum = 0;
		//아래로
	}
}



void MapHero::jump()
{
	if (jumpNum == _jumpNum)
		return;
	jumpment = iPointMake(0, -1) * jumpPower;
	jumpNum++;
}

void MapHero::applyJump(iPoint& movement, float dt)
{
	if (jumpment == iPointZero)
		return;

		iPoint addJump = jumpment * dt;
		movement += addJump;
		jumpment -= addJump;


}

void keyJump(iKeyState stat, iPoint point)
{
}


// 한 점에서 직선까지의 거리 (float)
float getDistanceLine0(iPoint p, iPoint sp, iPoint ep)
{
	iPoint n = ep - sp;
	float len = sqrtf(n.x * n.x + n.y * n.y);
	n /= len;


	iPoint m = p - sp;
	iPoint proj = n * max(0.0f, min(len, (m.x * n.x + m.y * n.y)));

	return iPointLength(m - proj);

	//iPoint v1 = p - sp;
	//iPoint v2 = ep - sp;
	//iPoint n = iPointVector(ep - sp);


	//iPoint v3 = iPointLength(v2) * (v1.x * n.x + v1.y * n.y);

	//return iPointLength(v1-v3);

}
