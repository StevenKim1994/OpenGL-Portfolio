#pragma once
#include "Object.h"
#include "stageTileInfo.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::setTex(Texture* tex)
{
	this->tex = tex;
}

void Object::setPosition(iPoint position)
{
	this->position = position;
}

void Object::setSize(iSize size)
{
	this->size = size;
}

void Object::setMovement(float movement)
{
	this->movement = movement;
}

void Object::setRange(float range)
{
	this->range = range;
}

void Object::setDamage(float damage)
{
	this->damage = damage;
}

void Object::setSpeed(float speed)
{
	this->speed = speed;
}

void Object::setHP(float hp)
{
	this->HP = hp;
}

void Object::setMP(float mp)
{
	this->MP = mp;
}

Texture* Object::getTex()
{
	return tex;
}

iPoint Object::getPosition()
{
	return position;
}

iSize Object::getSize()
{
	return size;
}

float Object::getMovement()
{
	return movement;
}

float Object::getRange()
{
	return range;
}

float Object::getDamage()
{
	return damage;
}

float Object::getSpeed()
{
	return speed;
}

float Object::getHp()
{
	return HP;
}

float Object::getMp()
{
	return MP;
}


extern MapTile* mt;
void Object::move(iPoint movement)
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
				int attr = mt[MapTileNumX * y + x].attr;
				if (attr == canNotMove || attr == endofTile)
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
				int attr = mt[MapTileNumX * y + x].attr;
				if (attr == canNotMove || attr == endofTile)
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
				if (mt[MapTileNumX * y + x].attr == canNotMove || (mt[MapTileNumX * y + x].attr == endofTile))
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

void Object::jump()
{
}

void Object::applyJump(iPoint& movement, float dt)
{
}

float getDistanceLine0(iPoint p, iPoint sp, iPoint ep)
{
	return 0.0f;
}

float getDistanceLine1(iPoint p, iPoint sp, iPoint ep)
{
	return 0.0f;
}
