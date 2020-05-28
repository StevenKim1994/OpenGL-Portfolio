#include "CanMove.h"

CanMove::CanMove()
{
	jumpNum = 0;
	jumpment = iPointZero;
	movement = 0;
	_jumpNum = 0;
}

CanMove::~CanMove()
{
}

void CanMove::move(iPoint movement, MapTile* maptile, int NumX, int NumY)
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
				if (maptile[NumX * y + x].attr == canNotMove)
				{
					//printf("!!!\n");
					col = true;
					min = MapTileWidth * (x + 1);
					break;
				}
				else if (maptile[NumX * y + x].attr == deadZone)
				{

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
		int min = MapTileWidth * NumX;
		for (int x = TRX + 1; x < NumX; x++)
		{
			bool col = false;
			for (int y = TRY; y < BRY + 1; y++)
			{
				if (maptile[NumX * y + x].attr == canNotMove)
				{
					//printf("!!!\n");
					col = true;
					min = MapTileWidth * x - 1;
					break;
				}

				else if (maptile[NumX * y + x].attr == deadZone)
				{
					printf("you die!\n");
					this->alive = false;
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
				if (maptile[NumX * y + x].attr == canNotMove)
				{
					//printf("!!!\n");
					col = true;
					min = MapTileHeight * (y + 1);
					break;
				}

				else if (maptile[NumX * y + x].attr == deadZone)
				{

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
		int min = MapTileHeight * NumY;
		for (int y = TLY + 1; y < NumY; y++)
		{
			bool col = false;
			for (int x = TLX; x < TRX + 1; x++)
			{
				if (maptile[NumX * y + x].attr == canNotMove)
				{
					//printf("!!!\n");
					col = true;
					min = MapTileHeight * y - 1;
					break;
				}
				else if (maptile[NumX * y + x].attr == deadZone)
				{

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

bool CanMove::moveForMouse(float dt, int NumX, int NumY)
{
	if (position != targetPosition)
	{
		if (position.x < targetPosition.x)
		{
			position.x += movement * dt;
			if (position.x > targetPosition.x)
				position.x = targetPosition.x;


		}
		else if (position.x > targetPosition.x)
		{
			position.x -= movement * dt;
			if (position.x < targetPosition.x)
				position.x = targetPosition.x;
		}

		if (position.y < targetPosition.y)
		{
			position.y += movement * dt;
			if (position.y > targetPosition.y)
				position.y = targetPosition.y;
		}
		else if (position.y > targetPosition.y)
		{
			position.y -= movement * dt;
			if (position.y < targetPosition.y)
				position.y = targetPosition.y;
		}
	}
	else
	{
		if (pathIndex < pathNum)
		{
			int index = path[pathIndex];
			targetPosition.x = MapTileWidth * (index % NumX) + MapTileWidth / 2;
			targetPosition.y = MapTileHeight * (index / NumX) + MapTileHeight / 2;
			pathIndex++;
		}
		else
			return true;
	}
	return false;
}

void CanMove::move(iPoint movement)
{
	position.x += movement.x;
	position.y += movement.y;

}


void CanMove::jump()
{
	if (jumpNum == _jumpNum)
		return;

	jumpNum++;
	jumpment = iPointMake(0, -1) * powJump;
}

void CanMove::applyJump(iPoint& movement, float dt)
{
	if (jumpment == iPointZero)
		return;

	iPoint mp = jumpment * dt;
	movement += mp;
	jumpment -= mp;
}

void CanMove::setMovement(float _movement)
{
	movement = _movement;
}

float CanMove::getMovement()
{
	return movement;
}
