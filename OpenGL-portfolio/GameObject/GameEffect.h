#pragma once

#include "iStd.h"
#include "Object.h"

//------------Number------------------//
void loadNumber();
void freeNumber();
void drawNumber(float dt, iPoint off);
void addNumber(int dmg, iPoint position);

//------------EffectHit------------------//
void loadEffectHit();
void freeEffectHit();
void drawEffectHit(float dt, iPoint off);
void addEffectHit(int index, iPoint p);


//------------Projectile-----------------//
void loadProjectile();
void freeProjectile();
void drawProjectile(float dt, iPoint off);
void addProjectile(int index, iPoint p, int direction, int speed, Object** target, int ObjNum);
