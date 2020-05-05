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

};