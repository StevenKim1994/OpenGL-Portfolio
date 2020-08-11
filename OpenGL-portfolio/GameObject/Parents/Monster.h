#pragma once
#include "CanMove.h"

#define mush_Num 2
#define goblin_Num 10

class Monster : public CanMove
{
public:
	Monster();
	virtual ~Monster();

public:
	virtual void setDmg(float dmg);
	virtual void setDetected_Player(bool check);
	virtual void setTarget(Object* obj);
	virtual bool getDetected_Player();
	virtual Object* getTarget();

public:

	int type; 
	float rateV;
	float r = 0.0f;
	float rValue = 1.0f;

	float aiTime, _aiTime;

	bool detected_Player;
	Object* target;


public:



};
