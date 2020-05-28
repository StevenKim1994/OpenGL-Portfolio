#pragma once

#include "Object.h"

class CanMove : public Object
{
public: CanMove();
	  virtual ~CanMove();

public:
	iPoint jumpment;
	iPoint v = iPointZero;


	int jumpNum;
	int _jumpNum;
	float movement;


	bool moveForMouse(float dt, int NumX, int NumY);
	void move(iPoint movement);
	void move(iPoint movement, MapTile* maptile, int NumX, int NumY);
	void jump();
	void applyJump(iPoint& movement, float dt);

public:
	void setMovement(float _movement);
	float getMovement();
};