#pragma once

#include "GameEffect.h"
#include "../game/sceneManager.h"
#include "Goblin.h"

struct Damage
{
	iStrTex* stDamage;
	iPoint p;
	float delta;

	bool paint(float dt, iPoint off);
};
#define Damage_delta 1.0f

Damage* _damage;
Damage** damage;
int damageNum;
#define _damageNum 100

Texture* methodStDamage(const char* str);

void loadNumber()
{
	_damage = (Damage*)malloc(sizeof(Damage) * _damageNum);
	for (int i = 0; i < _damageNum; i++)
	{
		Damage* d = &_damage[i];
		d->stDamage = new iStrTex(methodStDamage);
		d->p = iPointZero;
		d->delta = Damage_delta;
	}

	damage = (Damage**)malloc(sizeof(Damage*) * _damageNum);
	damageNum = 0;
}

void freeNumber()
{
	for (int i = 0; i < _damageNum; i++)
		delete _damage[i].stDamage;
	free(_damage);
	free(damage);
}
void drawNumber(float dt, iPoint off)
{
	for (int i = 0; i < damageNum; i++)
	{
		if (damage[i]->paint(dt, off))
		{
			damageNum--;
			for (int j = i; j < damageNum; j++)
				damage[j] = damage[1 + j];
			i--;
		}
	}
}
void addNumber(int dmg, iPoint position)
{
	for (int i = 0; i < _damageNum; i++)
	{
		Damage* d = &_damage[i];
		if (d->delta >= Damage_delta)
		{
			d->stDamage->setString("%d", dmg);
			d->p = position;
			d->delta = 0.0f;

			damage[damageNum] = d;
			damageNum++;
			return;
		}
	}
}

struct EffectHit
{
	iImage* img;
	iPoint p;
	int dir;

	bool paint(float dt, iPoint off)
	{
		img->paint(dt, p + off);
		img->leftRight = dir;
		if (img->animation)
			return false;
		return true;
	}
};
EffectHit** _ehEffectHit;
EffectHit** ehEffectHit;
int ehNum;
#define _ehNum 100

void loadEffectHit()
{
	int i;

	_ehEffectHit = (EffectHit**)malloc(sizeof(EffectHit*) * 1);

	iImage* img = new iImage();
	for (i = 0; i < 31; i++)
	{
		Texture* tex = createImage("assets/stage/hero/Knight/skill/hit/tile%d.png", i);
		img->addObject(tex);
		freeImage(tex);
	}
	img->position = iPointMake(-48, -48);
	img->_aniDt = 0.001f;
	img->_repeatNum = 1;

	_ehEffectHit[0] = (EffectHit*)malloc(sizeof(EffectHit) * _ehNum);
	for (i = 0; i < _ehNum; i++)
		_ehEffectHit[0][i].img = img->copy();

	delete img;

	ehEffectHit = (EffectHit**)malloc(sizeof(EffectHit*) * 1 * _ehNum);
	ehNum = 0;
}

void freeEffectHit()
{
	for (int j = 0; j < 1; j++)
	{
		for (int i = 0; i < _ehNum; i++)
			delete _ehEffectHit[j][i].img;
		free(_ehEffectHit[j]);
	}
	free(_ehEffectHit);
	free(ehEffectHit);
}

void drawEffectHit(float dt, iPoint off)
{
	setRGBA(1, 0, 0, 1);
	for (int i = 0; i < ehNum; i++)
	{
		if (ehEffectHit[i]->paint(dt, off))
		{
			ehNum--;
			for (int j = i; j < ehNum; j++)
				ehEffectHit[j] = ehEffectHit[1 + j];
		}
	}
	setRGBA(1, 1, 1, 1);
}

void addEffectHit(int index, iPoint p)
{
	for (int i = 0; i < _ehNum; i++)
	{
		EffectHit* eh = &_ehEffectHit[index][i];
		if (eh->img->animation == false)
		{
			eh->p = p;
			eh->dir = 0;
			eh->img->startAnimation();

			ehEffectHit[ehNum] = eh;
			ehNum++;
			return;
		}
	}
}

extern Object** orcs;
struct Projectile
{
	iImage* img;
	iPoint p;
	int dir;
	int speed;
	int targetNum;
	iSize rectSize = iSizeMake(32, 32);
	Object** target;

	bool paint(float dt, iPoint off)
	{

		if (dir == 1)
			p += iPointMake(1, 0) * speed;
		else
			p += iPointMake(-1, 0) * speed;
		img->paint(dt, p + off);
		img->leftRight = dir;

		extern int gameState;

		
			for (int i = 0; i < targetNum; i++)
			{

				if (containPoint(iPointMake(p.x, p.y + 32), iRectMake(target[i]->position.x, target[i]->position.y, 64, 64)))
				{
					target[i]->setDmg(7);
					addEffectHit(0, target[i]->position);
					//zoomCamera(target[i]->position, 1.5);
					return true;
				}
			}
		

		if (img->animation)
			return false;


		return true;

	}
};

Projectile** _projectile;
Projectile** projectile;
int projectNum;
#define _projectNum 100

void loadProjectile()
{
	int i;
	_projectile = (Projectile**)malloc(sizeof(Projectile*) * 1);

	iImage* img = new iImage();
	for (int i = 0; i < 61; i++)
	{
		Texture* tex = createImage("assets/stage/hero/Knight/skill2/tile%03d.png", i);
		img->addObject(tex);
		freeImage(tex);
	}
	img->position = iPointMake(-60, -60);
	img->_aniDt = 0.01f;
	img->_repeatNum = 0;

	_projectile[0] = (Projectile*)malloc(sizeof(Projectile) * _projectNum);
	for (i = 0; i < _projectNum; i++)
		_projectile[0][i].img = img->copy();

	delete img;

	projectile = (Projectile**)malloc(sizeof(Projectile*) * 1 * _projectNum);
	projectNum = 0;


}

void freeProjectile()
{
	for (int j = 0; j < 1; j++)
	{
		for (int i = 0; i < _projectNum; i++)
			delete _projectile[j][i].img;

		free(_projectile[j]);
	}
	free(_projectile);
	free(projectile);
}



void drawProjectile(float dt, iPoint off)
{
	for (int i = 0; i < projectNum; i++)
	{
		if (projectile[i]->paint(dt, off))
		{
			projectNum--;
			for (int j = i; j < projectNum; j++)
				projectile[j] = projectile[1 + j];
		}

	}
}

void addProjectile(int index, iPoint p, int direction, int speed, Object** ObjTarget, int TargetNum)
{
	for (int i = 0; i < _projectNum; i++)
	{
		Projectile* pj = &_projectile[index][i];
		if (pj->img->animation == false)
		{
			pj->p = p;
			pj->dir = direction;
			pj->speed = speed;
			pj->img->startAnimation();
			pj->target = ObjTarget;
			pj->targetNum = TargetNum;

			projectile[projectNum] = pj;
			projectNum++;
			return;
		}

	}
}

bool Damage::paint(float dt, iPoint off)
{
	float r = delta / Damage_delta;
	iPoint pp = p + off + iPointMake(0, -easeIn(r, 0, 200));
	float a = 1.0f - r;
	setRGBA(1, 1, 1, a);
	stDamage->paint(pp.x, pp.y, VCENTER | HCENTER);
	setRGBA(1, 1, 1, 1);

	delta += dt;
	if (delta < Damage_delta)
		return false;
	return true;
}

