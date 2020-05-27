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
	iPoint jumpment;
	int jumpNum;
	int _jumpNum; // 점프를 할수 있는 최대 수
	int direction;
	float movement; // 이동속도를 의미함.
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
	void setMovement(float movement);
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
	float getMovement();
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
	//function
	bool moveForMouse(float dt, int NumX, int NumY);
	void move(iPoint movement);
	void move(iPoint movement, MapTile* maptile, int NumX , int NumY);
	void jump();
	void applyJump(iPoint& movement, float dt);
	void setDmg(float dmg);
	void setBehave(ObjectBehave be, int dir);

	static void cbDeath(void* cb);
	static void cbHurt(void* cb);
	static void cbBehave(void* cb);
	static void cbSkill(void* cb);

	int path[1024];
	int pathNum;
	int pathIndex;
};

