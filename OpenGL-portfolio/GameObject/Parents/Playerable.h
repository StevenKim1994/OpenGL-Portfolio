#pragma once

#include "CanMove.h"

class Playerable : public CanMove
{
public:
	Playerable();
	virtual ~Playerable();

public:
	int kill;
	int level;
	float exp;
	int money;

public:
	bool moveForMouse(float dt, int NumX, int NumY);

	int getLevel();
	void setLevel(int _lv);
	void setExp(float _ex);
	float getExp();
};