#pragma once
#include "Monster.h"

#define mush_Num 2

class Mushroom : public Monster
{
public: Mushroom(int number);
	  virtual ~Mushroom();

public:
	void paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY);

	void setBehave(ObjectBehave be, int direction);

	void setDmg(float dmg);
	void Skill1();

	static void cbDeath(void* cb);
	static void cbHurt(void* cb);
	static void cbBehave(void* cb);
	static void cbSkill(void* cb);


public:
	void setDetected_Player(bool check);
	void setTarget(Object* obj);

	bool getDetected_Player();
	Object* getTarget();

private:
	bool detected_Player;
	iPoint Target_Pos;
	Object* Target;

public:
	int mush_number;
	//iImage** imgs;
	//iImage* img;

	float aiTime, _aiTime; // 반응까지에 걸리는 시간 _aiTime은 최대치

public:
	iImage* imgSkill1; // 공격스킬

};