#pragma once
#include "Monster.h"

Monster::Monster()
{
	Target = NULL;
	Target_Pos = iPointZero;
	_aiTime = 5.0f;
	alive = false;
	behave = ObjectBehave::ObjectBehave_NULL;
	detected_Player = NULL;
	direction = 0;
	imgs = NULL;
	img = NULL;
	rateV = NULL;
	roamingDt = NULL;
	_roamingDt = NULL;
}

Monster::~Monster()
{
}

void Monster::setDetected_Player(bool check)
{
}

void Monster::setTarget(Object* obj)
{
}

bool Monster::getDetected_Player()
{
	return false;
}

Object* Monster::getTarget()
{
	return nullptr;
}

void Monster::setBehave(ObjectBehave be, int direction)
{
}

void Monster::setDmg(float dmg)
{
}

void Monster::paint(float dt, iPoint offset)
{
}

void Monster::paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY)
{
}

void Monster::Skill1()
{
}

void Monster::Skill2()
{
}
