#pragma once
#include "stageTileInfo.h"
struct TileInfo
{
	int value;
	bool visit;
	int pathNum;
	int path[1024];

};

class iShortestPath
{
public:
	iShortestPath();
	virtual ~iShortestPath();

	void init(int* tiles, int tileX, int tileY);
	void dijkstra(int start, int end, int* path, int& pathNum);
	void removeDuplicate(int* path, int& pathNum);

public:
	int* tiles;
	int tileX, tileY;
	int tileXY;

	TileInfo* ti;
	int tiNum;


};


//extern int tiles[MapTileNumX * MapTileNumY];


