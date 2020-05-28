#pragma once
#include "Monster.h"


#define goblin_Num 10

class Goblin : public Monster
{
public: Goblin(int number);
	  virtual ~Goblin();

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
	int goblin_number;
	//iImage** imgs;
	//iImage* img;

	float aiTime, _aiTime; // 반응까지에 걸리는 시간 _aiTime은 최대치
};

#define orcAiTime {5.0f, 5.0f, 5.0f, 5.0f, 5.0f}