#pragma once
#include "iStd.h"
#include "Object.h"
#include "Monster.h"



class Orc : public Monster
{
public: Orc();
	  virtual ~Orc();

public: 
	


private:
	bool detected_Player;
	iPoint Target_Pos;
	Object* Target;

	float aiTime, _aiTime = 10.0f; // 반응까지에 걸리는 시간 _aiTime은 최대치


public:
	

	static void cbDeath(void* cb);
	static void cbBehave(void* cb);
	static void cbSkill(void* cb);

	void setDmg(float dmg);
	void setBehave(EnermyBehave be, int direction);
	void paint(float dt, iPoint offset);

	iImage** imgs;
	iImage* img;

	void Skill1();
	void Skill2();


	//settter
	void setDetected_Player(bool check);
	void setTarget(Object* obj); 


	//getter
	bool getDetected_Player();
	Object* getTarget();



};