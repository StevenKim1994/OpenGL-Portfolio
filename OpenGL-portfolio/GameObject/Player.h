#pragma once
#include "iStd.h"
#include "Object.h"

#define idle_aniNum 15
#define meleeAttack_aniNum 22
#define move_aniNum 8
#define jumpAndFall_aniNum 14
#define hurt_aniNum 100 // 임시


class Player : public Object
{
public:
	Player();
	virtual ~Player();

public:
	iImage* idle;
	iImage* meleeAttack;
	iImage* moving;
	iImage* jumping;
	iImage* fall;
	iImage* jumpAndFall;
	iImage* hurt;

	int state = 0; // 0 : idle, 1 : attack, 2 : moving
	int direction; // 바라보는 방향 



public : 
	void Skill1(); // 아직 어떤 스킬을 넣을지 결정하진 않았음.
	void Skill2();
	void Skill3(); 

public:
	
	

};

