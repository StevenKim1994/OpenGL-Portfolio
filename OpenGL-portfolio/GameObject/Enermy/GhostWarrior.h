#pragma once
#include "Monster.h"

#define ghostwarrior_Num 1

class GhostWarrior : public Monster
{
public:GhostWarrior(int number);
	  virtual ~GhostWarrior();

public:
	void paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY);

	void setBehave(ObjectBehave be, int dir);
	void Skill1();
	void Skill2();
	void MeteorSkill();
	void setDmg(float dmg);

	static void cbDeath(void* cb);
	static void cbBehave(void* cb);
	static void cbSkill(void* cb);
	static void cbMeleeAttack(void* cb);
	static void cbMeleeAttack2(void* cb);
	static void cbMeteorSkill(void* cb);

public:

	bool detected_Player;

	iPoint oldPosition;
	Object* Target;
	int Parse = 0; // 0: 플레이어를 발견하지 못한상태
	float parseDt = 0.0f;
	bool action = false;
	bool leftRight = false; // false : left, true : right;
	int count;
	int count2;
	float tempY;
public:
	float aiTime, _aiTime;

public:
	iImage* imgSkill1; //



};