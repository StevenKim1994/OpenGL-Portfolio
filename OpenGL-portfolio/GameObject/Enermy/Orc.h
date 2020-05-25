#pragma once
#include "iStd.h"
#include "Object.h"
#include "Monster.h"

#define orc_Num 10

class Orc : public Monster
{
public: Orc(int number);
	  virtual ~Orc();

public:
	void paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY);

	void setBehave(EnermyBehave be, int direction);
	void Skill1();
	void Skill2();
	void setDmg(float dmg);

	static void cbDeath(void* cb);
	static void cbHurt(void* cb);
	static void cbBehave(void* cb);
	static void cbSkill(void* cb);

public:
	//settter
	void setDetected_Player(bool check);
	void setTarget(Object* obj);

	//getter
	bool getDetected_Player();
	Object* getTarget();
private:
	bool detected_Player;
	iPoint Target_Pos;
	Object* Target;

public:
	int orc_number;
	iImage** imgs;
	iImage* img;

	float aiTime, _aiTime; // 반응까지에 걸리는 시간 _aiTime은 최대치
};

#define orcAiTime {5.0f, 5.0f, 5.0f, 5.0f, 5.0f}