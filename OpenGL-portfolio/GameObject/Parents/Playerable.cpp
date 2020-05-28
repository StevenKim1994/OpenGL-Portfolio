#include "Playerable.h"

Playerable::Playerable()
{
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
