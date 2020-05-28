#include "Playerable.h"

Playerable::Playerable()
{
	level = 1;
	kill = 0;
	exp = 0.0f;
}

Playerable::~Playerable()
{
}

bool Playerable::moveForMouse(float dt, int NumX, int NumY)
{
	if (position.x < targetPosition.x)
		setBehave(ObjectBehave::ObjectBehave_move, 1);

	else
		setBehave(ObjectBehave::ObjectBehave_move, 0);



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

int Playerable::getLevel()
{
	return level;
}

void Playerable::setLevel(int _lv)
{
	level = _lv;
}

void Playerable::setExp(float _ex)
{
	exp = _ex;
}

float Playerable::getExp()
{
	return exp;
}
