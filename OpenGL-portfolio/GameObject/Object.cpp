#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::setTex(Texture* tex)
{
}

void Object::setPosition(iPoint position)
{
}

void Object::setSize(iSize size)
{
}

void Object::setMovement(float movement)
{
}

void Object::setRange(float range)
{
}

void Object::setDamage(float damage)
{
}

void Object::setSpeed(float speed)
{
}

void Object::setHP(float hp)
{
}

void Object::setMP(float mp)
{
}

Texture* Object::getTex()
{
	return nullptr;
}

iPoint Object::getPosition()
{
	return iPoint();
}

iSize Object::getSize()
{
	return iSize();
}

float Object::getMovement()
{
	return 0.0f;
}

float Object::getRange()
{
	return 0.0f;
}

float Object::getDamage()
{
	return 0.0f;
}

float Object::getSpeed()
{
	return 0.0f;
}

float Object::getHp()
{
	return 0.0f;
}

float Object::getMp()
{
	return 0.0f;
}
