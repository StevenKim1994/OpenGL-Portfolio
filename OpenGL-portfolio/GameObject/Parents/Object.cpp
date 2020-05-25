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

void Object::setTargetPosition(iPoint targetPosition)
{
	this->targetPosition = targetPosition;
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

void Object::setMaxHp(float _hp)
{
	this->_HP = _hp;
}

void Object::setMaxMp(float _mp)
{
	this->_MP = _mp;
}

void Object::setMaxStamina(float _stamina)
{
	this->_Stamina = _stamina;
}

void Object::setStamina(float stamina)
{
	this->Stamina = stamina;
}

void Object::setName(const char* name)
{
	strcpy(this->name, name);
}

Texture* Object::getTex()
{
	return tex;
}

iPoint Object::getPosition()
{
	return position;
}

iPoint Object::getTargetPosition()
{
	return targetPosition;
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

float Object::getStamina()
{
	return Stamina;
}

float Object::getMaxHp()
{
	return _HP;
}

float Object::getMaxMP()
{
	return _MP;
}

float Object::getMaxStamina()
{
	return _Stamina;
}

const char* Object::getName()
{
	return name;
}





void Object::move(iPoint movement, MapTile* maptile )
{
	iPoint mp = movement;
	
	int NumX;
	int NumY;

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
				if (maptile[StageMapTileNumX * y + x].attr == canNotMove)
				{
					//printf("!!!\n");
					col = true;
					min = MapTileWidth * (x + 1);
					break;
				}
				else if (maptile[StageMapTileNumX * y + x].attr == deadZone)
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
		int min = MapTileWidth * StageMapTileNumX;
		for (int x = TRX + 1; x < StageMapTileNumX; x++)
		{
			bool col = false;
			for (int y = TRY; y < BRY + 1; y++)
			{
				if (maptile[StageMapTileNumX * y + x].attr == canNotMove)
				{
					//printf("!!!\n");
					col = true;
					min = MapTileWidth * x - 1;
					break;
				}

				else if (maptile[StageMapTileNumX * y + x].attr == deadZone)
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
				if (maptile[StageMapTileNumX * y + x].attr == canNotMove)
				{
					//printf("!!!\n");
					col = true;
					min = MapTileHeight * (y + 1);
					break;
				}

				else if (maptile[StageMapTileNumX * y + x].attr == deadZone)
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
		int min = MapTileHeight * StageMapTileNumY;
		for (int y = TLY + 1; y < StageMapTileNumY; y++)
		{
			bool col = false;
			for (int x = TLX; x < TRX + 1; x++)
			{
				if (maptile[StageMapTileNumX * y + x].attr == canNotMove)
				{
					//printf("!!!\n");
					col = true;
					min = MapTileHeight * y - 1;
					break;
				}
				else if (maptile[StageMapTileNumX * y + x].attr == deadZone)
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

bool Object::moveForMouse(float dt)
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
			targetPosition.x = MapTileWidth * (index % StageMapTileNumX) + MapTileWidth / 2;
			targetPosition.y = MapTileHeight * (index / StageMapTileNumX) + MapTileHeight / 2;
			pathIndex++;
		}
		else
			return true;
	}
	return false;
}

void Object::move(iPoint movement)
{
	position.x += movement.x;
	position.y += movement.y;

}


void Object::jump()
{
	if (jumpNum == _jumpNum)
		return;

	jumpNum++;
	jumpment = iPointMake(0, -1) * powJump;
}

void Object::applyJump(iPoint& movement, float dt)
{
	if (jumpment == iPointZero)
		return;

	iPoint mp = jumpment * dt;
	movement += mp;
	jumpment -= mp;
}

float getDistanceLine0(iPoint p, iPoint sp, iPoint ep)
{
	iPoint n = ep - sp;
	float len = sqrtf(n.x * n.x + n.y * n.y);
	n /= len;

	iPoint m = p - sp;
	iPoint proj = n * (m.x * n.x + m.y * n.y);

	return iPointLength(m - proj);
}

float getDistanceLine1(iPoint p, iPoint sp, iPoint ep)
{
	iPoint n = ep - sp;
	float len = sqrtf(n.x * n.x + n.y * n.y);

	n /= len;

	iPoint m = p - sp;
	iPoint proj = n * max(0.0f, min((m.x * n.x + m.y * n.y), len));

	return iPointLength(m - proj);
}
