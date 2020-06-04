#pragma once

#include "iStd.h"
#include "stageTileInfo.h"

#define PlayerWidth 16
#define PlayerHeight 16
#define PlayerSpeed 200

enum class ObjectBehave
{
	ObjectBehave_NULL = -1,
	ObjectBehave_idle = 0,
	ObjectBehave_meleeAttack1,
	ObjectBehave_meleeAttack2,
	ObjectBehave_move,
	ObjectBehave_jump,
	ObjectBehave_fall,
	ObjectBehave_hurt,
	ObjectBehave_death,
	ObjectBehave_num,
};

struct ObjInfo
{
	const char* path;
	int num;
	float sizeRate;
	iPoint p; // 축 조절하는 거
	// add
	float aniDt;
	int repeatNum;
	iColor4f color = {1, 1, 1, 1};
};


class Object
{
public: Object();
	 virtual ~Object();

public:

	iImage** imgs;
	iImage* img;
	
	Texture* tex;
	iPoint position;
	iPoint targetPosition;
	iSize size;

	int direction;
	float range;
	float damage;
	float speed; // 공격속도를 의미함.
	float _speed;
	float HP;
	float _HP;
	float MP;
	float _MP;
	float Stamina;
	float _Stamina;
	char name[64];

public:
	bool alive;
public: 

	//setter
	void setTex(Texture* tex);
	void setPosition(iPoint position);
	void setTargetPosition(iPoint targetPosition);
	void setSize(iSize size);

	void setRange(float range);
	void setDamage(float damage);
	void setSpeed(float speed);
	void setHP(float hp);
	void setMP(float mp);
	void setMaxHp(float _hp);
	void setMaxMp(float _mp);
	void setMaxStamina(float _stamina);
	void setStamina(float stamina);
	void setName(const char* name);

	//getter
	Texture* getTex();
	iPoint getPosition();
	iPoint getTargetPosition();
	iSize getSize();
	
	float getRange();
	float getDamage();
	float getSpeed();
	float getHp();
	float getMp();
	float getStamina();
	float getMaxHp();
	float getMaxMP();
	float getMaxStamina();
	const char* getName();


	

public:
	ObjectBehave behave;
	virtual void setDmg(float dmg);
	virtual void setBehave(ObjectBehave be, int dir);

	static void cbDeath(void* cb);
	static void cbHurt(void* cb);
	static void cbBehave(void* cb);
	static void cbSkill(void* cb);

	int path[1024];
	int pathNum;
	int pathIndex;
};

