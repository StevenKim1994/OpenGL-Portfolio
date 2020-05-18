#pragma once
#include "iStd.h"
#include "Object.h"
#include "Monster.h"

enum Behave
{
	Behave_idle = 0,
	Behave_meleeAttack,
	Behave_move,
	Behave_jumpAndFall,

	Behave_num,
};

class Player : public Object
{
public:
	Player();
	virtual ~Player();

	static void cbBehave(iImage* img);
	static void cbSkill(iImage* skillimg);
	void setBehave(Behave be, int direction);
	void paint(float dt, iPoint offset);
	
	
	iImage** imgs;
	iImage* img;

	Behave behave;
	int direction;
	int kill = 0; // 몬스터 처치수

	//override func
	bool moveForMouse(float dt);
	
public:
	iImage* imgSkill; // 근접 스킬
	iImage* imgRange; // 원거리 스킬
	iImage* imgBuff; // 버프 스킬
	iImage* Ultimate; // 궁극기
	void Skill1(Monster** enermys, int enermyNum);
	void Skill2();
	void Skill3();

public:



};



