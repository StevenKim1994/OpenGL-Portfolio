#pragma once

struct iSortData
{
	int index;
	float y;
};

class iSort
{
public:
	iSort();
	virtual ~iSort();

	void init();
	void add(float y);
	void update();

	int get(int i);

public:
	iSortData* sd;
	int sdNum;
};

#define _sdNum 200

