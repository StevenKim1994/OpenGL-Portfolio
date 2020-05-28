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

public:
	bool moveForMouse(float dt, int NumX, int NumY);
};