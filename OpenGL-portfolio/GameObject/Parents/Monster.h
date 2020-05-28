#pragma once
#include "Object.h"

class Monster : public Object
{
public:
	Monster();
	virtual ~Monster();


public:
	float rateV;
	float r = 0.0f;
	float rValue = 1.0f;
};
