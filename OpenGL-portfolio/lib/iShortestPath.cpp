#include "iShortestPath.h"

#include "iStd.h"
iShortestPath::iShortestPath()
{
	tiles = NULL;
	tileX = 0;
	tileY = 0;

	ti = NULL;
	tiNum = 0;
}

iShortestPath::~iShortestPath()
{
	if (ti)
		free(ti);
}

void iShortestPath::init(int* tiles, int tileX, int tileY)
{
	this->tiles = tiles;
	this->tileX = tileX;
	this->tileY = tileY;

	tileXY = tileX * tileY;
	
	if (tiNum < tileXY)
	{
		if (ti)
			free(ti);

		ti = (TileInfo*)malloc(sizeof(TileInfo) * tileXY);
		tiNum = tileXY;
	}

}

void iShortestPath::dijkstra(int start, int end, int* path, int& pathNum)
{
	for (int i = 0; i < tileXY; i++)
	{
		TileInfo* t = &ti[i];
		t->value = canNotMove;
		t->visit = false;
		t->pathNum = 0;
	}


	TileInfo* t = &ti[start];
	t->value = 0;
	t->path[0] = start;
	t->pathNum = 1;

	while (1)
	{
		int curr = -1, next;
		int min = canNotMove;
		for (int i = 0; i < tileXY; i++)
		{
			if (ti[i].value < min && ti[i].visit == false)
			{
				curr = i;
				min = ti[i].value;
			}
		}
		if (curr == -1)
			break;

		TileInfo* tiCurr = &ti[curr], * tiNext;
		tiCurr->visit = true;

		for (int i = 0; i < 4; i++)
		{
			if (i == 0) {// left
				if (curr % tileX == 0) continue;
				next = curr - 1;
			}
			else if (i == 1) {// right
				if (curr % tileX == tileX - 1) continue;
				next = curr + 1;
			}
			else if (i == 2) {// up
				if (curr / tileX == 0) continue;
				next = curr - tileX;
			}
			else if (i == 3) {// down
				if (curr / tileX == tileY - 1) continue;
				next = curr + tileX;
			}
			if (tiles[next] == canNotMove) continue; // 갈수 없는 곳이면 무시함.

			tiNext = &ti[next];
			int value = tiCurr->value + tiles[next];
			if (value < tiNext->value)
			{
				tiNext->value = value;
				tiNext->pathNum = tiCurr->pathNum;
				memcpy(tiNext->path, tiCurr->path, sizeof(int) * tiCurr->pathNum);
				tiNext->path[tiCurr->pathNum] = next;
				tiNext->pathNum++;
			}
		}
	}

	pathNum = ti[end].pathNum;
	memcpy(path, ti[end].path, sizeof(int) * pathNum);

}

void iShortestPath::removeDuplicate(int* path, int& pathNum)
{

	for (int i = 0; i < pathNum - 2; i++)
	{
		int cp = path[i];
		int cx = cp % tileX;
		int cy = cp / tileX;

		int np = path[i + 1];
		int nx = np % tileX;
		int ny = np / tileX;

		if (cx == nx)
		{
			int n = pathNum;
			for (int j = 2 + i; j < n; j++)
			{
				int p = path[j];
				int x = p % tileX;

				if (cx == x)
				{
					//duplicate
					memcpy(&path[i + 1], &path[j], sizeof(int) * (n - j));
					pathNum--;

				}
				else
					break;
			}
		}
		else if (cy == ny)
		{
			int n = pathNum;
			for (int j = 2 + i; j < n; j++)
			{
				int p = path[j];
				int y = p / tileX;

				if (cy == y)
				{
					//duplicate
					memcpy(&path[i + 1], &path[j], sizeof(int) * (n - j));
					pathNum--;

				}
				else
					break;
			}
		}

	}


}
