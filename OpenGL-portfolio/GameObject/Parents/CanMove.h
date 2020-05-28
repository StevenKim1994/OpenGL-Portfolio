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
};