#pragma once
#include "iStd.h"
#include "Object.h"
#include "Monster.h"



class Player : public Object
{
public:
	Player();
	virtual ~Player();

	static void cbBehave(void* cb);
	static void cbSkill(void* cb);
	void setBehave(ObjectBehave be, int direction);
	void paint(float dt, iPoint offset);
	
	
	iImage** imgs;
	iImage* img;

	ObjectBehave behave;
	int direction;
	int kill = 0; // 몬스터 처치수

	

	//override func
	bool moveForMouse(float dt, int NumX, int NumY);
	
public:
	iImage* imgSkill; // 근접 스킬
	iImage* imgSKillHit; // 타격시 이펙트
	iImage* imgRange; // 원거리 스킬
	iImage* imgBuff; // 버프 스킬
	iImage* Ultimate; // 궁극기
	void Skill1();
	void Skill2();
	void Skill3();

public:



};

extern Player* hero;

