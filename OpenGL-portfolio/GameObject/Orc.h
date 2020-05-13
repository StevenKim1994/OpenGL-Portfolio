#pragma once
#include "iStd.h"
#include "Object.h"

enum orcBehave
{
	orcBehave_idle = 0,
	orcBehave_meleeAttack,
	orcBehave_move,
	orcBehave_jumpAndFall,
	orcBehave_hurt,
	orcBehave_death,



	orcBehave_num,
};


class Orc : public Object
{
public: Orc();
	  virtual ~Orc();



private:
	bool detected_Player;
	iPoint Target_Pos;
	Object* Target;

public:
	
	orcBehave behave;
	int direction;

	static void cbBehave(iImage* img);
	static void cbSkill(iImage* skillimg);

	void setBehave(orcBehave be, int direction);
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