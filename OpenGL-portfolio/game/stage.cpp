
#include "stage.h"
#include "Player.h"

//static Player* player = Player::GetInstance();

uint8 tileAttr[(MapTileNumX + 1) * (MapTileNumY + 1)] =
{
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
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
};


MapTile* mt;
iPoint offMt;


//Player* player;

MapHero* player;

void loadStage()
{
	//player = Player::GetInstance();

	//printf("%f\n", Player::GetInstance()->getHp());

	int i, num = (MapTileNumX + 1) * (MapTileNumY + 1);

	mt = (MapTile*)malloc(sizeof(MapTile) * num);
	
	for (i = 0; i < num; i++)
	{
		MapTile* t = &mt[i];
		t->attr = tileAttr[i];
	}

	offMt = iPointZero;

	player = (MapHero*)malloc(sizeof(MapHero));
	player->position = iPointMake(MapTileWidth * 3 + MapTileWidth / 2, MapTileHeight * 1 + MapTileHeight / 2);
	player->size = iSizeMake(MapCharWidth, MapCharHeight);
	player->speed = MapCharSpeed;

	player->jumpment = iPointZero;
	player->jumpNum = 0;
	player->_jumpNum = 2;



}

void freeStage()
{
	free(mt);
	free(player);


}

void drawStage(float dt)
{
	int i, num = MapTileNumX * MapTileNumY;

	for (i = 0; i < num; i++)
	{
		MapTile* t = &mt[i];
		switch (t->attr)
		{
		case 0: setRGBA(title_color_canMove); break; // 이동가능
		case 1: setRGBA(title_color_ladder); break; // 사다리
		case 5: setRGBA(title_color_end); break; // 맵의 끝

		case 99: setRGBA(title_color_canNotMove); break; // 이동할수 없는 곳
		}

		float x = offMt.x + MapTileWidth * (i % MapTileNumX);
		float y = offMt.y + MapTileHeight * (i / MapTileNumX);
		fillRect(x, y, MapTileWidth, MapTileHeight);
		setRGBA(0, 0, 0, 1);
		drawRect(x + 2, y + 2, MapTileWidth - 4, MapTileHeight - 4);
	}

	setRGBA(hero_color);
	fillRect(player->position.x + offMt.x - player->size.width / 2,
		player->position.y + offMt.y - player->size.height / 2, player->size.width, player->size.height);

	iPoint movement = iPointMake(0, 1) * powGravity * dt;

	player->applyJump(movement, dt);



	if (getKeyDown() & keyboard_space)
	{
		player->jump();
	}

	uint32 keyStat = getKeyStat();
	iPoint v = iPointZero;

	if (keyStat & keyboard_left) v.x = -1;
	else if (keyStat & keyboard_right)v.x = 1;

	if (keyStat & keyboard_up) v.y = -1;
	else if (keyStat & keyboard_down) v.y = 1;

	if (v != iPointZero)
	{
		v /= iPointLength(v);
		iPoint mp = v * (player->speed * dt);
		player->move(mp + movement);

		iPoint vp = offMt + player->position;

		if (vp.x < devSize.width * 0.3333f)
		{
			offMt.x += (devSize.width * 0.3333f - vp.x);
			if (offMt.x > 0)
				offMt.x = 0;
			// 왼쪽으로 넘어갈 경우
		}

		else if (vp.x > devSize.width * 0.6666f)
		{
			offMt.x += (devSize.width * 0.6666f - vp.x);
			if (offMt.x < devSize.width - MapTileWidth * MapTileNumX)
				offMt.x = devSize.width - MapTileWidth * MapTileNumX;
			// 오른쪽으로 넘어갈 경우
		}

		if (vp.y < devSize.height * 0.3333f)
		{
			offMt.y += (devSize.height * 0.3333f - vp.y);
			if (offMt.y > 0)
				offMt.y = 0;
			// 위쪽으로 넘어갈 경우
		}

		else if (vp.y > devSize.height * 0.6666f)
		{
			offMt.y += (devSize.height * 0.6666f - vp.y);
			if (offMt.y < devSize.height - MapTileHeight * MapTileNumY);
			offMt.y = devSize.height - MapTileHeight * MapTileNumY;
			//아래쪽으로 넘어갈 경우
		}

	}

	else // v == iPointZero
	{
		player->move(movement);

		iPoint vp = offMt + player->position;

		if (vp.x != devSize.width / 2)
		{
			if (vp.x < devSize.width / 2)
			{
				offMt.x += natureSpeed * dt;
				vp.x = offMt.x += player->position.x;
				if (vp.x > devSize.width / 2)
					offMt.x = devSize.width / 2 - player->position.x;
			}
			
			else
			{
				offMt.x -= natureSpeed * dt;
				vp.x = offMt.x + player->position.x;
				if (vp.x < devSize.width / 2)
					offMt.x = devSize.width / 2 - player->position.x;
			}

			if (offMt.x > 0)
				offMt.x = 0;

			else if (offMt.x < devSize.width - MapTileWidth * MapTileHeight)
				offMt.x = devSize.width - MapTileWidth * MapTileHeight;
		}

		if (vp.y != devSize.height / 2)
		{
			if (vp.y < devSize.height / 2)
			{
				offMt.y += natureSpeed * dt;
				vp.y = offMt.y + player->position.y;
				if (vp.y > devSize.height / 2)
					offMt.y = devSize.height / 2 - player->position.y;
			}
			else
			{
				offMt.y -= natureSpeed * dt;
				vp.y = offMt.y + player->position.y;
				if (vp.y < devSize.height / 2)
					offMt.y = devSize.height / 2 - player->position.y;
			}
			
			if (offMt.y > 0)
				offMt.y = 0;

			else if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
				offMt.y = devSize.height - MapTileHeight * MapTileNumY;
		}
	}



}

void keyStage(iKeyState stat, iPoint point)
{
}

void MapHero::move(iPoint movement)
{
	if (movement.x < 0)
	{
		// left;
		int tlx = position.x - size.width / 2; tlx /= MapTileWidth;
		int tly = position.y - size.height / 2; tly /= MapTileHeight;
		int bly = position.y + size.height / 2; bly /= MapTileHeight;
		int min = 0;

		for (int x = tlx - 1; x > -1; x--)
		{
			bool col = false;
			for (int y = tly; y < bly + 1; y++)
			{
				if (mt[MapTileNumX * y * x].attr == canMove)
				{
					col = true;
					min = MapTileWidth * (x + 1);
					break;
				}
			}
			if (col)
				break;
			
		}

		position.x += movement.x;
		if (position.x < min + size.width / 2)
			position.x = min + size.width / 2;
	}
	else if (movement.x > 0)
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
				if (mt[MapTileNumX * y + x].attr == canNotMove)
				{
					col = true;
					min = MapTileWidth * x - 1;
					break;
				}
			}
			if (col)
				break;
		}

		position.x += movement.x;
		if (position.x > min - size.width / 2)
			position.x = min - size.width / 2;
	}


	if (movement.y < 0)
	{
		//up
		int TLY = position.y - size.height / 2; TLY /= MapTileHeight;
		int TLX = position.x - size.width / 2; TLX /= MapTileWidth;
		int TRX = position.x + size.width / 2; TRX /= MapTileWidth;
		int min = 0;

		for (int y = TLY - 1; y > -1; y--)
		{
			bool col = false;

			for (int x = TLX; x < TRX + 1; x++)
			{
				if (mt[MapTileNumX * y + x].attr == canMove)
				{
					col = true;
					min = MapTileHeight * (y + 1);
					break;
				}
			}
			if (col)
				break;
		}
		
		position.y += movement.y;
		if (position.y < min + size.height / 2)
			position.y = min + size.height / 2;
		
	}

	else if (movement.y > 0)
	{
		//down
		int TLY = position.y + size.height / 2; TLY /= MapTileHeight;
		int TLX = position.x - size.width / 2; TLX /= MapTileWidth;
		int TRX = position.x + size.width / 2; TRX /= MapTileWidth;
		int min = MapTileHeight * MapTileNumY;
		for (int y = TLY + 1; y < MapTileNumY; y++)
		{
			bool col = false;
			for (int x = TLX; x < TRX + 1; x++)
			{
				if (mt[MapTileNumX * y + x].attr == canMove)
				{
					col = true;
					min = MapTileHeight * y - 1;
					break;
				}
			}
			if (col)
				break;
		}
		position.y += movement.y;
		if (position.y > min - size.height / 2)
			position.y = min - size.height / 2;

		if (position.y == min - size.height / 2)
			jumpNum = 0;
	}

}

void MapHero::jump()
{
	if (jumpNum == _jumpNum)
		return;

	jumpNum++;
	jumpment = iPointMake(0, -1) * powJump;
}

void MapHero::applyJump(iPoint& movement, float dt)
{
	if (jumpment == iPointZero)
		return;

	iPoint mp = jumpment * dt;
	movement += mp;
	jumpment -= mp;
}
