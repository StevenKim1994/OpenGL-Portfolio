#pragma once

#include "iStd.h"

class Object
{
public: Object();
	  ~Object();

private: 
	Texture* tex;
	iPoint position;
	iSize size;
	iPoint jumpment;
	int jumpNum;
	int _jumpNum; // 점프를 할수 있는 최대 수
	float movement; // 이동속도를 의미함.
	float range;
	float damage;
	float speed; // 공격속도를 의미함.
	float HP;
	float MP;


public: 

	//setter
	void setTex(Texture* tex);
	void setPosition(iPoint position);
	void setSize(iSize size);
	void setMovement(float movement);
	void setRange(float range);
	void setDamage(float damage);
	void setSpeed(float speed);
	void setHP(float hp);
	void setMP(float mp);

	//getter
	Texture* getTex();
	iPoint getPosition();
	iSize getSize();
	float getMovement();
	float getRange();
	float getDamage();
	float getSpeed();
	float getHp();
	float getMp();

public:
	//function
	void move(iPoint movement);
	void jump();
	void applyJump(iPoint& movement, float dt);
};

// 한점에서 직선까지의 거리
float getDistanceLine0(iPoint p, iPoint sp, iPoint ep);
// 한점에서 선분까지의 거리
float getDistanceLine1(iPoint p, iPoint sp, iPoint ep);

#define PlayerWidth 30
#define PlayerHeight 30
#define PlayerSpeed 200

#define PlayerColor 0,0,1,1
