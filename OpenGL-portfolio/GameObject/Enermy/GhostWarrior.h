#pragma once
#include "Monster.h"

#define ghostwarrior_Num 1

class GhostWarrior : public Monster
{
public:GhostWarrior(int number);
	  virtual ~GhostWarrior();

public:
	void paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY);

	void setBehave(ObjectBehave be, int direction);
	void Skill1();
	void Skill2();
	void setDmg(float dmg);

	static void cbDeath(void* cb);
	static void cbBehave(void* cb);
	static void cbSkill(void* cb);

public:

	bool detected_Player;
	iPoint Target_Pos;
	Object* Target;

public:
	
	float aiTime, _aiTime;

};