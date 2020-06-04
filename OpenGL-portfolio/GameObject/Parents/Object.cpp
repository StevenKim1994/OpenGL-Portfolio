#pragma once
#include "Object.h"

#include "GameEffect.h"
#include "stageTileInfo.h"





Object::Object()
{
	imgs = NULL;
	img = NULL;

	HP = 0;
	MP = 0;
	Stamina = 0;
	_Stamina = 0;
	_MP = 0;
	_HP = 0;
	speed = 0;
	_speed = 0;
	alive = false;

	pathIndex = 0;
	position = iPointZero;
	range = 0;
	size = iSizeZero;
	damage = 0;
	targetPosition = iPointZero;
	tex = NULL;
	
	
	
}

Object::~Object()
{
}

void Object::setTex(Texture* tex)
{
	this->tex = tex;
}

void Object::setPosition(iPoint position)
{
	this->position = position;
}

void Object::setTargetPosition(iPoint targetPosition)
{
	this->targetPosition = targetPosition;
}

void Object::setSize(iSize size)
{
	this->size = size;
}


void Object::setRange(float range)
{
	this->range = range;
}

void Object::setDamage(float damage)
{
	this->damage = damage;
}

void Object::setSpeed(float speed)
{
	this->speed = speed;
}

void Object::setHP(float hp)
{
	this->HP = hp;
}

void Object::setMP(float mp)
{
	this->MP = mp;
}

void Object::setMaxHp(float _hp)
{
	this->_HP = _hp;
}

void Object::setMaxMp(float _mp)
{
	this->_MP = _mp;
}

void Object::setMaxStamina(float _stamina)
{
	this->_Stamina = _stamina;
}

void Object::setStamina(float stamina)
{
	this->Stamina = stamina;
}

void Object::setName(const char* name)
{
	strcpy(this->name, name);
}

Texture* Object::getTex()
{
	return tex;
}

iPoint Object::getPosition()
{
	return position;
}

iPoint Object::getTargetPosition()
{
	return targetPosition;
}

iSize Object::getSize()
{
	return size;
}


float Object::getRange()
{
	return range;
}

float Object::getDamage()
{
	return damage;
}

float Object::getSpeed()
{
	return speed;
}

float Object::getHp()
{
	return HP;
}

float Object::getMp()
{
	return MP;
}

float Object::getStamina()
{
	return Stamina;
}

float Object::getMaxHp()
{
	return _HP;
}

float Object::getMaxMP()
{
	return _MP;
}

float Object::getMaxStamina()
{
	return _Stamina;
}

const char* Object::getName()
{
	return name;
}


void Object::setDmg(float dmg)
{
	ObjectBehave be = behave;
	int dir = direction;

	HP -= dmg;
	if(HP> 0)
	{
		be = ObjectBehave::ObjectBehave_hurt;
	}
	else if(HP<0)
	{
		HP = 0;
		be = ObjectBehave::ObjectBehave_death;
	}

	setBehave(be, dir);

	addNumber(dmg, position + iPointMake(0, -50));
}

void Object::setBehave(ObjectBehave be, int dir)
{
	if(behave != be || direction != dir)
	{
		behave = be;
		img = imgs[(int)be];
		if (be == ObjectBehave::ObjectBehave_death)
			img->startAnimation(cbDeath, this);
		else if (be == ObjectBehave::ObjectBehave_hurt)
			img->startAnimation(cbHurt, this);
		else if (be == ObjectBehave::ObjectBehave_meleeAttack1)
			img->startAnimation(cbSkill, this);
		else
			img->startAnimation(cbBehave, img);
		direction = dir;
	}
}



void Object::cbDeath(void* cb)
{
	Object* o = (Object*)cb;
	o->alive = false;

	
	
}

void Object::cbHurt(void* cb)
{
	Object* o = (Object*)cb;
	o->setBehave(ObjectBehave::ObjectBehave_idle, o->direction);
}

void Object::cbBehave(void* cb)
{
	iImage* i = (iImage*)cb;
}

void Object::cbSkill(void* cb)
{
	Object* o = (Object*)cb;
}

