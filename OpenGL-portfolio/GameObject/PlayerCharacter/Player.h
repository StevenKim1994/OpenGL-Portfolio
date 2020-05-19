#pragma once
#include "iStd.h"
#include "Object.h"
#include "Monster.h"
#include "PlayerParent.h"


class Player : public PlayerParent
{
public:
	Player();
	virtual ~Player();

	static void cbBehave(iImage* img);
	static void cbSkill(iImage* skillimg);
	void setBehave(PlayerBehave be, int direction);
	void paint(float dt, iPoint offset);
	
	
	iImage** imgs;
	iImage* img;

	PlayerBehave behave;
	int direction;
	int kill = 0; // 몬스터 처치수

	//override func
	bool moveForMouse(float dt);
	
public:
	iImage* imgSkill; // 근접 스킬
	iImage* imgRange; // 원거리 스킬
	iImage* imgBuff; // 버프 스킬
	iImage* Ultimate; // 궁극기
	void Skill1();
	void Skill2();
	void Skill3();

public:



};



